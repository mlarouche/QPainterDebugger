#include "ConstructorCall.h"

// Local includes
#include "ClassConstructor.h"
#include "NameMangling.h"

ConstructorCall::ConstructorCall(const QString &className, Scope *context)
: FunctionCall(className,context)
{
}

ConstructorCall::~ConstructorCall()
{
}

QVariant ConstructorCall::evaluate()
{
	QString mangledConstructorName = NameMangling::mangleFunctionName(m_functionName, m_parameters);

	ClassConstructor* constructor = context()->constructor(mangledConstructorName);
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
