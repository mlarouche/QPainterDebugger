#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ASTNode.h"

class Expression : public ASTNode
{
public:
	Expression();
	Expression(PainterContext* context);

	virtual QVariant::Type type() const = 0;
};

#endif
