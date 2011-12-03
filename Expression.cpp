#include "Expression.h"

Expression::Expression(const QVariant& value)
: m_value(value)
{
}

Expression::Expression(PainterContext *context)
: ASTNode(context)
{
}

Expression::~Expression()
{
}

QVariant::Type Expression::type() const
{
	return m_value.type();
}

QVariant Expression::evaluate()
{
	return m_value;
}
