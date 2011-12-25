#ifndef CLASSSCOPE_H
#define CLASSSCOPE_H

#include "Scope.h"

// Qt includes
#include <QtCore/QSharedPointer>

// Local includes
#include "BindedFunction.h"
#include "ClassPrototype.h"
#include "Expression.h"

template<class T>
class ClassScope : public Scope
{
public:
	ClassScope(ClassPrototype<T>* prototype)
	: m_classInstance(0), m_prototype(prototype)
	{
	}

	virtual ~ClassScope()
	{
		delete m_classInstance;
	}

	virtual QVariant asQVariant() const
	{
		return QVariant(*m_classInstance);
	}

	bool isValidFunction(const QString &functionName) const
	{
		return m_prototype->isValidFunction(functionName);
	}

	QVariant execute(const QString &functionName, const QList<Expression*> &parameters)
	{
		BindedFunction<T> *function = m_prototype->function(functionName);
		return function->execute(m_classInstance, parameters);
	}

	T* m_classInstance;

protected:
	ClassPrototype<T>* m_prototype;
};

#endif
