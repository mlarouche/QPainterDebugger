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
	Scope* scopeToUse;
	QString identifier = context()->findIdentifierAndScope(m_identifier, scopeToUse);

	bool isClass = scopeToUse->hasScope(identifier);
	if(isClass)
	{
		return scopeToUse->scope(identifier)->asQVariant().type();
	}
	else
	{
		if(!scopeToUse->hasVariable(identifier))
		{
			return QVariant::Invalid;
		}

		return scopeToUse->variable(identifier).type();
	}
}

QVariant IdentifierExpression::evaluate()
{
	Scope* scopeToUse;
	QString identifier = context()->findIdentifierAndScope(m_identifier, scopeToUse);

	bool isClass = scopeToUse->hasScope(identifier);
	if(isClass)
	{
		return scopeToUse->scope(identifier)->asQVariant();
	}
	else
	{
		if(!scopeToUse->hasVariable(identifier))
		{
			showErrorMessage(QString("%1 is not defined.").arg(identifier));
			return QVariant();
		}

		return scopeToUse->variable(identifier);
	}
}
