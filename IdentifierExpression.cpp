#include "IdentifierExpression.h"

IdentifierExpression::IdentifierExpression(const QString &identifier, Scope* context)
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
	if(!context()->hasVariable(m_identifier))
	{
		showErrorMessage(QString("%1 is not defined.").arg(m_identifier));
		return QVariant();
	}

	return context()->variable(m_identifier);
}
