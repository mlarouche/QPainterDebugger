#include "PainterContext.h"

#include "PainterCommand.h"

#include "Expression.h"

PainterContext::PainterContext()
{
	bindFunctions();
}

PainterContext::~PainterContext()
{
	qDeleteAll(m_functions);
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

void PainterContext::bindFunctions()
{
	BIND_PAINTER_FUNCTION_6(drawArc,int,int,int,int,int,int);
	BIND_PAINTER_FUNCTION_6(drawChord,int,int,int,int,int,int);
	BIND_PAINTER_FUNCTION_4(drawEllipse,int,int,int,int);
	BIND_PAINTER_FUNCTION_4(drawLine, int,int,int,int);
	BIND_PAINTER_FUNCTION_6(drawPie, int,int,int,int,int,int);
	BIND_PAINTER_FUNCTION_2(drawPoint,int,int);
	BIND_PAINTER_FUNCTION_4(drawRect,int,int,int,int);
	BIND_PAINTER_FUNCTION_3(drawText,int,int,QString);
	BIND_PAINTER_FUNCTION_4(eraseRect,int,int,int,int);
	BIND_PAINTER_FUNCTION_0(resetTransform);
	BIND_PAINTER_FUNCTION_0(restore);
	BIND_PAINTER_FUNCTION_0(save);
}
