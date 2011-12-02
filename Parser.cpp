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

	// root ::= statement*
	qDebug("root");
	RootNode* root = new RootNode;

	while(m_token != Lexer::EndOfFile)
	{
		root->addChild(parseStatement());

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
		// TODO: Error
		return 0;
	}

	QString functionName = lexer->lastReadValue().toString();

	FunctionCall* functionCall = new FunctionCall(functionName, m_context);

	//Ignore (
	getNextToken();

	// Parse expression untill we find the right parenthesis
	while(m_token != Lexer::RightParenthesis)
	{
		functionCall->addParameter(parseExpression());
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
			//TODO: SetError() !
			qDebug("Token %d not expected here", (int)m_token);
			break;
	}

	return 0;
}
