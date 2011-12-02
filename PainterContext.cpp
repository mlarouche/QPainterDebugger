#include "PainterContext.h"

#include "PainterCommand.h"

PainterContext::PainterContext()
{
}

QVariant PainterContext::variable(const QString &identifier)
{
	return m_variables.value(identifier);
}

void PainterContext::setVariable(const QString &identifier, const QVariant &value)
{
	m_variables.insert(identifier,value);
}

bool PainterContext::isValidFunction(const QString &functionName) const
{
	return m_functions.contains(functionName);
}

PainterCommand* PainterContext::function(const QString &functionName) const
{
	return m_functions.value(functionName);
}

void PainterContext::setFunction(const QString &functionName, PainterCommand* function)
{
	m_functions.insert(functionName, function);
}
