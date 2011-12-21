#include "Scope.h"

Scope::Scope()
{
}

Scope::~Scope()
{
	qDeleteAll(m_children);
}

bool Scope::hasVariable(const QString &variableName)
{
	return m_variables.contains(variableName);
}

QVariant Scope::variable(const QString &identifier)
{
	return m_variables.value(identifier);
}

void Scope::setVariable(const QString &identifier, const QVariant &value)
{
	m_variables.insert(identifier,value);
}

void Scope::addScope(const QString &name, Scope *child)
{
	m_children.insert(name, child);
}

Scope* Scope::scope(const QString &name)
{
	if(!m_children.contains(name))
	{
		return 0;
	}

	return m_children.value(name);
}
