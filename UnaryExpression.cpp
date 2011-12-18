#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(UnaryExpression::UnaryExpressionType type, Expression* expression)
	: Expression(), m_type(type), m_expression(expression)
{
}

UnaryExpression::~UnaryExpression()
{
	delete m_expression;
}

QVariant::Type UnaryExpression::type() const
{
	return m_expression->type();
}

QVariant UnaryExpression::evaluate()
{
	QVariant value = m_expression->evaluate();

	switch(m_type)
	{
	case UnaryExpression::Negative:
	{
		if(value.type() == QVariant::String)
		{
			showErrorMessage("You cannot negate a string value");
			return QVariant();
		}
		else
		{
			if(value.type() == QVariant::Double)
			{
				return -value.toDouble();
			}
			if(value.type() == QVariant::Int)
			{
				return -value.toInt();
			}
		}
		break;
	}
	default:
			break;
	}

	return value;
}
