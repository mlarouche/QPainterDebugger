#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression
{
public:
	enum UnaryExpressionType
	{
		None,
		Negative
	};

	UnaryExpression(UnaryExpressionType type, Expression* expression);
	~UnaryExpression();

	QVariant evaluate();

private:
	UnaryExpressionType m_type;
	Expression* m_expression;
};

#endif
