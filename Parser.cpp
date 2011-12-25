#include "Parser.h"

// Local includes
#include "ASTNode.h"
#include "BinaryExpression.h"
#include "ConstructorCall.h"
#include "Expression.h"
#include "FunctionCall.h"
#include "IdentifierExpression.h"
#include "Lexer.h"
#include "LiteralExpression.h"
#include "PainterContext.h"
#include "RootNode.h"
#include "UnaryExpression.h"
#include "VariableAssignment.h"
#include "VariableCreation.h"

BinaryExpression::BinaryExpressionType tokenToBinaryExpressionType(Lexer::Token token)
{
	switch(token)
	{
		case Lexer::PlusSign:
			return BinaryExpression::Addition;
		case Lexer::MinusSign:
			return BinaryExpression::Subtraction;
		case Lexer::MulSign:
			return BinaryExpression::Multiplication;
		case Lexer::DivSign:
			return BinaryExpression::Division;
		case Lexer::ModuloSign:
			return BinaryExpression::Modulo;
		default:
			return BinaryExpression::None;
	}
}

Parser::Parser()
: lexer(0), m_context(0), m_currentLine(0), m_currentColumn(0)
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
	return QString("Error at %1:%2: %3").arg(m_currentLine).arg(m_currentColumn).arg(m_errorMessage);
}

void Parser::setContext(PainterContext *context)
{
	m_context = context;
}

void Parser::getNextToken()
{
	if(lexer)
	{
		m_currentLine = lexer->currentLine();
		m_currentColumn = lexer->currentColumn();
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
	// statement ::= functionCall | variableAssignment | variableCreation
	qDebug("statement");

	Lexer::Token lookAhead = lexer->lookAhead();

	switch(lookAhead)
	{
		case Lexer::Identifier:
		{
			QString qualifiedIdentifier = parseQualifiedIdentifier();
			Lexer::Token identLookAhead = lexer->lookAhead();
			if(identLookAhead == Lexer::LeftParenthesis)
			{
				return parseFunctionCall(qualifiedIdentifier);
			}
			else if(identLookAhead == Lexer::EqualSign)
			{
				return parseVariableAssignment(qualifiedIdentifier);
			}
		}
		case Lexer::Keyword_var:
			return parseVariableCreation();
		default:
			m_errorMessage = "You can only use statements here.";
			return 0;
	}
}

Expression* Parser::parseFunctionCall(const QString &qualifiedIdentifier)
{
	// functionCall ::= qualifiedIdentifier '(' expression? (',' expression)* ')'
	qDebug("functionCall");

	QString functionName = qualifiedIdentifier;
	QString lastIdentifier = qualifiedIdentifier.mid(qualifiedIdentifier.lastIndexOf('.'));

	FunctionCall* functionCall = 0;

	// A function call can be a constructor call
	if(m_context->hasClassPrototype(lastIdentifier))
	{
		functionCall = new ConstructorCall(functionName, m_context);
	}
	else
	{
		functionCall = new FunctionCall(functionName, m_context);
	}

	//Ignore (
	getNextToken();

	if(lexer->lookAhead() == Lexer::RightParenthesis)
	{
		getNextToken();
	}
	else
	{
		// Parse expression untill we find the right parenthesis
		while(m_token != Lexer::RightParenthesis)
		{
			Expression *parameter = parseExpression();
			if(!parameter)
			{
				delete functionCall;
				return 0;
			}

			functionCall->addParameter(parameter);
			getNextToken();
		}
	}

	return functionCall;
}

ASTNode* Parser::parseVariableCreation()
{
	qDebug("variableCreation");
	// variableCreation ::= 'var' IDENTIFIER '=' expression

	// Eat 'var' token
	getNextToken();

	// Parse variable name
	getNextToken();
	QString variableName = lexer->lastReadValue().toString();

	// Eat '='
	getNextToken();

	// Parse expression
	Expression* expression = parseExpression();
	if(!expression)
	{
		m_errorMessage = "You can only assign an expression to a variable";
		return 0;
	}

	return new VariableCreation(variableName, expression, m_context);
}

ASTNode* Parser::parseVariableAssignment(const QString &qualifiedIdentifier)
{
	qDebug("variableAssignment");
	// variableAssignment ::= qualifiedIdentifier '=' expression

	// Eat '='
	getNextToken();

	// Parse expression
	Expression* expression = parseExpression();
	if(!expression)
	{
		m_errorMessage = "You can only assign an expression to a variable";
		return 0;
	}

	return new VariableAssignment(qualifiedIdentifier, expression, m_context);
}

QString Parser::parseQualifiedIdentifier(bool firstIdentifierIsParsed)
{
	// qualifiedIdentifier ::= IDENTIFIER ('.' IDENTIFIER)*
	if(!firstIdentifierIsParsed)
	{
		getNextToken();
	}

	QString qualifiedIdentifier;

	while(lexer->lookAhead() == Lexer::ScopeOperator)
	{
		QString scopeName = lexer->lastReadValue().toString();

		qualifiedIdentifier += scopeName;
		qualifiedIdentifier += '.';

		// Eat scope operator
		getNextToken();

		// Read next identifier
		getNextToken();
	}

	qualifiedIdentifier += lexer->lastReadValue().toString();

	return qualifiedIdentifier;
}

Expression* Parser::parseTerm()
{
	// term ::= INTEGER_LITERAL
	//		| FLOAT_LITERAL
	//		| STRING_LITERAL
	//		| BOOL_LITERAL
	//		| qualifiedIdentifier
	//		| '(' expression ')'
	//		| functionCall

	qDebug("term");
	getNextToken();

	switch(m_token)
	{
		case Lexer::IntegerLiteral:
			return new LiteralExpression(lexer->lastReadValue().toInt());
		case Lexer::StringLiteral:
			return new LiteralExpression(lexer->lastReadValue().toString());
		case Lexer::FloatLiteral:
			return new LiteralExpression(lexer->lastReadValue().toDouble());
		case Lexer::BoolLiteral:
			return new LiteralExpression(lexer->lastReadValue().toBool());
		case Lexer::Identifier:
		{
			QString qualifiedIdentifier = parseQualifiedIdentifier(true);
			if(lexer->lookAhead() == Lexer::LeftParenthesis)
			{
				return parseFunctionCall(qualifiedIdentifier);
			}
			else
			{
				return new IdentifierExpression(qualifiedIdentifier, m_context);
			}
		}
		case Lexer::LeftParenthesis:
		{
			Expression *parenthesisExpression = parseExpression();

			// Eat )
			getNextToken();

			return parenthesisExpression;
		}
		default:
			m_errorMessage = "Invalid term found !";
			qDebug("Token %d not expected here", (int)m_token);
			break;
	}

	return 0;
}

Expression* Parser::parseUnaryExpression()
{
	// unaryExpression ::= '-'? term
	qDebug("unaryExpression");
	Lexer::Token lookAhead = lexer->lookAhead();
	if(lookAhead == Lexer::MinusSign)
	{
		// Eat '-'
		getNextToken();
		return new UnaryExpression(UnaryExpression::Negative, parseTerm());
	}
	else
	{
		return parseTerm();
	}
}

Expression* Parser::parseMultiplicativeExpression()
{
	// multiplicativeExpression ::= unaryExpression (('*'|'/'|) unaryExpression)*
	qDebug("multiplicativeExpression");
	Expression* left = parseUnaryExpression();

	Lexer::Token lookAhead = lexer->lookAhead();

	if(lookAhead == Lexer::MulSign || lookAhead == Lexer::DivSign || lookAhead == Lexer::ModuloSign)
	{
		getNextToken();
		Expression* right = parseUnaryExpression();

		Lexer::Token secondLookAhead = lexer->lookAhead();
		if(secondLookAhead == Lexer::MulSign || secondLookAhead == Lexer::DivSign || secondLookAhead == Lexer::ModuloSign)
		{
			getNextToken();
			BinaryExpression *binOpRight = new BinaryExpression(tokenToBinaryExpressionType(secondLookAhead), right, parseMultiplicativeExpression());
			return new BinaryExpression(tokenToBinaryExpressionType(lookAhead), left, binOpRight);
		}
		else
		{
			return new BinaryExpression(tokenToBinaryExpressionType(lookAhead), left, right);
		}
	}
	else
	{
		return left;
	}
}

Expression* Parser::parseAdditiveExpression()
{
	// additiveExpression ::= multiplicativeExpression (('+' | '-') multiplicativeExpression)*
	qDebug("additiveExpression");
	Expression* left = parseMultiplicativeExpression();

	Lexer::Token lookAhead = lexer->lookAhead();

	if(lookAhead == Lexer::PlusSign|| lookAhead == Lexer::MinusSign)
	{
		getNextToken();
		Expression* right = parseMultiplicativeExpression();

		Lexer::Token secondLookAhead = lexer->lookAhead();
		if(secondLookAhead == Lexer::PlusSign || secondLookAhead == Lexer::MinusSign)
		{
			getNextToken();
			BinaryExpression *binOpRight = new BinaryExpression(tokenToBinaryExpressionType(secondLookAhead), right, parseAdditiveExpression());
			return new BinaryExpression(tokenToBinaryExpressionType(lookAhead), left, binOpRight);
		}
		else
		{
			return new BinaryExpression(tokenToBinaryExpressionType(lookAhead), left, right);
		}
	}
	else
	{
		return left;
	}
}

Expression* Parser::parseExpression()
{
	// expression :: additiveExpression
	qDebug("expression");
	return parseAdditiveExpression();
}
