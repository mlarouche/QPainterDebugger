#include "IdentifierExpression.h"

IdentifierExpression::IdentifierExpression(const QString &identifier, PainterContext* context)
: Expression(context), m_identifier(identifier)
{
}

IdentifierExpression::~IdentifierExpression()
{
}

QVariant::Type IdentifierExpression::type() const
{
	return context()->variable(m_identifier).type();
}

QVariant IdentifierExpression::evaluate()
{
	return context()->variable(m_identifier);
}
