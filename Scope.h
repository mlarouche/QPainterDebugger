#ifndef SCOPE_H
#define SCOPE_H

#include <QtCore/QString>
#include <QtCore/QHash>
#include <QtCore/QVariant>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>

#include "ClassPrototype.h"

class ClassConstructor;
class Expression;

class Scope
{
public:
	Scope();
	~Scope();

	bool hasVariable(const QString &variableName) const;
	QVariant variable(const QString &identifier) const;
	void setVariable(const QString &identifier, const QVariant &value);

	bool hasScope(const QString &name) const;
	void addScope(const QString& name, Scope* child);
	Scope *scope(const QString& name) const;

	QString findIdentifierAndScope(const QString &qualifiedIdentifier, Scope *& foundScope);

	virtual QVariant asQVariant() const
	{
		return QVariant();
	}

	virtual bool isValidFunction(const QString &/*functionName*/) const
	{
		return false;
	}

	virtual QVariant execute(const QString &/*functionName*/, const QList<Expression*> &/*parameters*/)
	{
		return QVariant();
	}

	bool hasClassPrototype(const QString &className) const
	{
		return m_classPrototypes.contains(className);
	}

	void addClassPrototype(const QString &className, IClassPrototype* prototype);

	IClassPrototype* classPrototype(const QString &className) const
	{
		return m_classPrototypes.value(className);
	}

	void addClassConstructor(const QString &constructorName, ClassConstructor* constructor);
	ClassConstructor* constructor(const QString &constructorName)
	{
		return m_constructors.value(constructorName);
	}

private:
	QHash<QString,QVariant> m_variables;
	QHash<QString,Scope*> m_children;
	QHash<QString,ClassConstructor*> m_constructors;
	QHash<QString,IClassPrototype*> m_classPrototypes;
};

class ClassInstance
{
public:
	ClassInstance()
	: classInstance(0)
	{
	}

	ClassInstance(Scope* _classInstance)
	: classInstance(_classInstance)
	{
	}

	Scope* classInstance;
};

Q_DECLARE_METATYPE(ClassInstance)

#endif
