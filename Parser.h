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

private:
	Expression* parseExpression();
	ASTNode* parseStatement();
	ASTNode* parseFunctionCall();

private:
	void getNextToken();

private:
	Lexer* lexer;
	PainterContext* m_context;
	Lexer::Token m_token;
};

#endif
