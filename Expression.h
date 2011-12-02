#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ASTNode.h"

class Expression : public ASTNode
{
public:
	Expression(const QVariant& value);
	Expression(PainterContext* context);

	virtual QVariant::Type type() const;

	virtual QVariant evaluate();

private:
	QVariant m_value;
};

#endif
