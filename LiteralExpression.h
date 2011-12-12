#ifndef LITERAL_EXPRESSION_H
#define LITERAL_EXPRESSION_H

#include "Expression.h"

class LiteralExpression : public Expression
{
public:
	LiteralExpression(const QVariant& value);
	virtual ~LiteralExpression();

	virtual QVariant::Type type() const;

	virtual QVariant evaluate();

private:
	QVariant m_value;
};

#endif
