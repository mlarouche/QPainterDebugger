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
		foreach(QString mangledName, m_functions.keys())
		{
			int returnIndexOf = mangledName.indexOf('?')+1;
			int argIndexOf = mangledName.indexOf("|");
			QString strippedFunctionName = mangledName.mid(returnIndexOf, argIndexOf-returnIndexOf);
			if(strippedFunctionName.compare(functionName) == 0)
			{
				return true;
			}
		}

		return false;
	}

	QMetaType::Type functionReturnType(const QString &functionName) const
	{
		foreach(QString mangledName, m_functions.keys())
		{
			int returnIndexOf = mangledName.indexOf('?')+1;
			int argIndexOf = mangledName.indexOf("|");
			QString strippedFunctionName = mangledName.mid(returnIndexOf, argIndexOf-returnIndexOf);
			if(strippedFunctionName.compare(functionName) == 0)
			{
				QString returnType = mangledName.left(mangledName.indexOf("?"));
				return (QMetaType::Type)QMetaType::type(qPrintable(returnType));
			}
		}

		return QMetaType::Void;
	}

	BindedFunction<T>* function(const QString &functionName) const
	{
		foreach(QString mangledName, m_functions.keys())
		{
			QString functionNameWithNoReturnType = mangledName.mid(mangledName.indexOf('?'));
			if(functionNameWithNoReturnType.compare(functionName) == 0)
			{
				return m_functions.value(mangledName);
			}
		}

		return NULL;
	}

	void setFunction(const QString &functionName, BindedFunction<T>* function)
	{
		m_functions.insert(functionName, function);
	}

private:
	QHash<QString,BindedFunction<T>*> m_functions;
};

#endif
