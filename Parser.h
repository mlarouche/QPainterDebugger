#ifndef PARSER_H
#define PARSER_H

#include <QtCore/QString>

#include "ASTNode.h"
#include "Lexer.h"

class Expression;
class PainterContext;
class Scope;

class Parser
{
public:
	Parser();
	~Parser();

	void setContext(PainterContext* context);

	ASTNode* parse(const QString& sourceText);

	bool hasError() const;

	QString errorMessage() const;

private:
	ASTNode* parseStatement();
	Expression* parseFunctionCall(const QString &qualifiedIdentifier = QString());
	ASTNode* parseVariableAssignment();
	Expression* parseTerm();
	Expression* parseUnaryExpression();
	Expression* parseMultiplicativeExpression();
	Expression* parseAdditiveExpression();
	Expression* parseExpression();
	QString parseQualifiedIdentifier(bool firstIdentifierIsParsed = false);

private:
	void getNextToken();

private:
	Lexer* lexer;
	PainterContext* m_context;
	Lexer::Token m_token;
	QString m_errorMessage;
	int m_currentLine;
	int m_currentColumn;
};

#endif
