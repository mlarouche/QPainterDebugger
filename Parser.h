#ifndef PARSER_H
#define PARSER_H

#include <QtCore/QString>

#include "ASTNode.h"
#include "Lexer.h"

class Expression;
class PainterContext;

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
	ASTNode* parseFunctionCall();
	ASTNode* parseVariableAssignment();
	Expression* parseTerm();
	Expression* parseMultiplicativeExpression();
	Expression* parseAdditiveExpression();
	Expression* parseExpression();

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
