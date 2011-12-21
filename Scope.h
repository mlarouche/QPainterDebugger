#ifndef SCOPE_H
#define SCOPE_H

#include <QtCore/QString>
#include <QtCore/QHash>
#include <QtCore/QVariant>

class Scope
{
public:
	Scope();
	~Scope();

	bool hasVariable(const QString &variableName);
	QVariant variable(const QString &identifier);
	void setVariable(const QString &identifier, const QVariant &value);

	void addScope(const QString& name, Scope* child);
	Scope *scope(const QString& name);

private:
	QHash<QString,QVariant> m_variables;
	QHash<QString,Scope*> m_children;
};

#endif
