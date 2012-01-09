#include "Scope.h"

#include "ClassConstructor.h"

Scope::Scope()
{
}

Scope::~Scope()
{
	qDeleteAll(m_children);
	qDeleteAll(m_constructors);
	qDeleteAll(m_classPrototypes);
}

bool Scope::hasVariable(const QString &variableName) const
{
	return m_variables.contains(variableName);
}

QVariant Scope::variable(const QString &identifier) const
{
	return m_variables.value(identifier);
}

void Scope::setVariable(const QString &identifier, const QVariant &value)
{
	m_variables.insert(identifier,value);
}

bool Scope::hasScope(const QString &name) const
{
	return m_children.contains(name);
}

void Scope::addScope(const QString &name, Scope *child)
{
	m_children.insert(name, child);
}

Scope* Scope::scope(const QString &name) const
{
	if(hasScope(name))
	{
		return m_children.value(name);
	}
	else
	{
		return 0;
	}
}

QString Scope::findIdentifierAndScope(const QString &qualifiedIdentifier, Scope *& foundScope)
{
	foundScope = this;

	QString identifier;

	int lastPosition = 0;
	int position = 0;

	position = qualifiedIdentifier.indexOf('.');
	while((position = qualifiedIdentifier.indexOf('.',lastPosition)) != -1)
	{
		identifier = qualifiedIdentifier.mid(lastPosition, position);
		foundScope = foundScope->scope(identifier);
		lastPosition = position+1;
	}

	identifier = qualifiedIdentifier.mid(lastPosition, position);
	return identifier;
}

void Scope::addClassPrototype(const QString &className, IClassPrototype* prototype)
{
	m_classPrototypes.insert(className,prototype);
}

void Scope::addClassConstructor(const QString &constructorName, ClassConstructor* constructor)
{
	m_constructors.insert(constructorName, constructor);
}

ClassConstructor* Scope::constructor(const QString &constructorName)
{
	return m_constructors.value(constructorName);
}
