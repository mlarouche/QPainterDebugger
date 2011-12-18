#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression
{
public:
	enum BinaryExpressionType
	{
		None = 0,
		Addition,
		Subtraction,
		Multiplication,
		Division,
		Modulo
	};

	BinaryExpression(BinaryExpressionType type, Expression* left, Expression* right);

	QVariant::Type type() const;
	QVariant evaluate();

private:
	QVariant doAdd(QVariant left, QVariant right);
	QVariant doSub(QVariant left, QVariant right);
	QVariant doMul(QVariant left, QVariant right);
	QVariant doDiv(QVariant left, QVariant right);
	QVariant doModulo(QVariant left, QVariant right);

private:
	BinaryExpressionType m_type;
	Expression* m_left;
	Expression* m_right;
};

#endif
