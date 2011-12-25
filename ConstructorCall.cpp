#include "ConstructorCall.h"

#include "ClassConstructor.h"

ConstructorCall::ConstructorCall(const QString &className, Scope *context)
: FunctionCall(className,context)
{
}

ConstructorCall::~ConstructorCall()
{
}

QVariant ConstructorCall::evaluate()
{
	ClassConstructor* constructor = context()->constructor(m_functionName);
	if(constructor)
	{
		ClassInstance newInstance(constructor->create(context(), m_parameters));

		return QVariant::fromValue(newInstance);
	}
	else
	{
		return QVariant();
	}
}
