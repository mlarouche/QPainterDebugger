#include "LiteralExpression.h"

LiteralExpression::LiteralExpression(const QVariant& value)
: m_value(value)
{
}

LiteralExpression::~LiteralExpression()
{
}

QVariant::Type LiteralExpression::type() const
{
	return m_value.type();
}

QVariant LiteralExpression::evaluate()
{
	return m_value;
}
