#include "Parser.h"

// Local includes
#include "ASTNode.h"
#include "Expression.h"
#include "FunctionCall.h"
#include "Lexer.h"
#include "IdentifierExpression.h"
#include "RootNode.h"

Parser::Parser()
: lexer(0), m_context(0)
{
}

Parser::~Parser()
{
	delete lexer;
}

bool Parser::hasError() const
{
	return !m_errorMessage.isEmpty();
}

QString Parser::errorMessage() const
{
	return QString("Error at %1:%2: %3").arg(lexer->currentLine()).arg(lexer->currentColumn()).arg(m_errorMessage);
}

void Parser::setContext(PainterContext *context)
{
	m_context = context;
}

void Parser::getNextToken()
{
	if(lexer)
	{
		m_token = lexer->getNextToken();
	}
}

ASTNode* Parser::parse(const QString& sourceText)
{
	if(lexer)
	{
		delete lexer;
		lexer = 0;
	}
	lexer = new Lexer(sourceText);

	// root ::= statement* EOF
	qDebug("root");
	RootNode* root = new RootNode;

	while(m_token != Lexer::EndOfFile)
	{
		ASTNode* child = parseStatement();
		if (!child)
		{
			return 0;
		}

		root->addChild(child);

		// Check for end of file token
		if(lexer->lookAhead() == Lexer::EndOfFile)
		{
			getNextToken();
		}
	}

	return root;
}

ASTNode* Parser::parseStatement()
{
	qDebug("statement");
	// statement ::= functionCall
	return parseFunctionCall();
}

ASTNode* Parser::parseFunctionCall()
{
	qDebug("functionCall");
	// functionCall ::= IDENTIFIER '(' expression? (',' expression)* ')'
	getNextToken();

	if(m_token != Lexer::Identifier)
	{
		m_errorMessage = "Function name expected";
		// TODO: Error
		return 0;
	}

	QString functionName = lexer->lastReadValue().toString();

	if(!m_context->isValidFunction(functionName))
	{
		m_errorMessage = QString("%1 is not defined").arg(functionName);
		return 0;
	}

	FunctionCall* functionCall = new FunctionCall(functionName, m_context);

	//Ignore (
	getNextToken();

	// Parse expression untill we find the right parenthesis
	while(m_token != Lexer::RightParenthesis)
	{
		Expression *parameter = parseExpression();
		if(!parameter)
		{
			return 0;
		}

		functionCall->addParameter(parameter);
		getNextToken();
	}

	return functionCall;
}

Expression* Parser::parseExpression()
{
	qDebug("expression");
	getNextToken();

	// expression ::= NUMBERLITERAL | STRINGLITERAL | IDENTIFIER
	switch(m_token)
	{
		case Lexer::NumberLiteral:
		case Lexer::StringLiteral:
			return new Expression(lexer->lastReadValue());
		case Lexer::Identifier:
			return new IdentifierExpression(lexer->lastReadValue().toString(), m_context);
		default:
			m_errorMessage = "Invalid expression found !";
			qDebug("Token %d not expected here", (int)m_token);
			break;
	}

	return 0;
}
