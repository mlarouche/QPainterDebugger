#ifndef CLASSPROTOTYPE_H
#define CLASSPROTOTYPE_H

#include <QtCore/QHash>
#include <QtCore/QString>

#include "BindedFunction.h"

class IClassPrototype
{
public:
	IClassPrototype()
	{}
};

template<class T>
class ClassPrototype : public IClassPrototype
{
public:
	ClassPrototype()
	{}

	bool isValidFunction(const QString &functionName) const
	{
		return m_functions.contains(functionName);
	}

	BindedFunction<T>* function(const QString &functionName) const
	{
		return m_functions.value(functionName);
	}

	void setFunction(const QString &functionName, BindedFunction<T>* function)
	{
		m_functions.insert(functionName, function);
	}

private:
	QHash<QString,BindedFunction<T>*> m_functions;
};

#endif
