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
	Expression* parseExpression();
	ASTNode* parseStatement();
	ASTNode* parseFunctionCall();
	ASTNode* parseVariableAssignment();

private:
	void getNextToken();

private:
	Lexer* lexer;
	PainterContext* m_context;
	Lexer::Token m_token;
	QString m_errorMessage;
};

#endif
