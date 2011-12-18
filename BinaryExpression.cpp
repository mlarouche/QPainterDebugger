#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(BinaryExpressionType type, Expression* left, Expression* right)
: Expression(), m_type(type), m_left(left), m_right(right)
{
}

QVariant::Type BinaryExpression::type() const
{
	return m_left->type();
}

QVariant BinaryExpression::evaluate()
{
	QVariant leftValue = m_left->evaluate();
	QVariant rightValue = m_right->evaluate();
	QVariant result;

	switch(m_type)
	{
		case BinaryExpression::Addition:
			result = doAdd(leftValue,rightValue);
			break;
		case BinaryExpression::Subtraction:
			result = doSub(leftValue, rightValue);
			break;
		case BinaryExpression::Multiplication:
			result = doMul(leftValue, rightValue);
			break;
		case BinaryExpression::Division:
			result = doDiv(leftValue, rightValue);
			break;
		case BinaryExpression::Modulo:
			result = doModulo(leftValue, rightValue);
			break;
		default:
			break;
	}

	return result;
}

QVariant BinaryExpression::doAdd(QVariant left, QVariant right)
{
	switch(left.type())
	{
		case QVariant::Int:
			return left.toInt() + right.toInt();
		case QVariant::Double:
			return left.toFloat() + right.toFloat();
		case QVariant::String:
			return left.toString() + right.toString();
		default:
			return QVariant();
	}
}

QVariant BinaryExpression::doSub(QVariant left, QVariant right)
{
	if(left.type() == QVariant::String || right.type() == QVariant::String)
	{
		showErrorMessage("You cannot subtract two strings");
		return QVariant();
	}

	switch(left.type())
	{
		case QVariant::Int:
			return left.toInt() - right.toInt();
		case QVariant::Double:
			return left.toDouble() - right.toDouble();
		default:
			return QVariant();
	}
}

QVariant BinaryExpression::doMul(QVariant left, QVariant right)
{
	if(left.type() == QVariant::String || right.type() == QVariant::String)
	{
		showErrorMessage("You cannot multiply with a string");
		return QVariant();
	}

	switch(left.type())
	{
		case QVariant::Int:
			return left.toInt() * right.toInt();
		case QVariant::Double:
			return left.toDouble() * right.toDouble();
		default:
			return QVariant();
	}
}

QVariant BinaryExpression::doDiv(QVariant left, QVariant right)
{
	if(left.type() == QVariant::String || right.type() == QVariant::String)
	{
		showErrorMessage("You cannot divide with a string");
		return QVariant();
	}

	switch(left.type())
	{
		case QVariant::Int:
			return left.toInt() / right.toInt();
		case QVariant::Double:
			return left.toDouble() / right.toDouble();
		default:
			return QVariant();
	}
}

QVariant BinaryExpression::doModulo(QVariant left, QVariant right)
{
	if(left.type() == QVariant::String || right.type() == QVariant::String)
	{
		showErrorMessage("You cannot get the remainder of a string");
		return QVariant();
	}

	switch(left.type())
	{
		case QVariant::Int:
		case QVariant::Double:
			return left.toInt() % right.toInt();
		default:
			return QVariant();
	}
}
