#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ASTNode.h"

class Expression : public ASTNode
{
public:
	Expression();
	Expression(PainterContext* context);
};

#endif
