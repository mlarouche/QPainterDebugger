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

bool PainterContext::hasVariable(const QString &variableName)
{
	return m_variables.contains(variableName);
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
	BIND_PAINTER_PROCEDURE_6(drawArc,int,int,int,int,int,int);
	BIND_PAINTER_PROCEDURE_6(drawChord,int,int,int,int,int,int);
	BIND_PAINTER_PROCEDURE_4(drawEllipse,int,int,int,int);
	BIND_PAINTER_PROCEDURE_4(drawLine, int,int,int,int);
	BIND_PAINTER_PROCEDURE_6(drawPie, int,int,int,int,int,int);
	BIND_PAINTER_PROCEDURE_2(drawPoint,int,int);
	BIND_PAINTER_PROCEDURE_4(drawRect,int,int,int,int);
	BIND_PAINTER_PROCEDURE_3(drawText,int,int,QString);
	BIND_PAINTER_PROCEDURE_4(eraseRect,int,int,int,int);
	BIND_PAINTER_PROCEDURE_0(resetTransform);
	BIND_PAINTER_PROCEDURE_0(restore);
	BIND_PAINTER_PROCEDURE_1(rotate,qreal);
	BIND_PAINTER_PROCEDURE_0(save);
	BIND_PAINTER_PROCEDURE_2(scale,qreal,qreal);
	BIND_PAINTER_PROCEDURE_2(setBrushOrigin,int,int);
	BIND_PAINTER_PROCEDURE_1(setClipping,bool);
	BIND_PAINTER_PROCEDURE_1(setOpacity,qreal);
	BIND_PAINTER_PROCEDURE_1(setViewTransformEnabled,bool);
	BIND_PAINTER_PROCEDURE_2(shear, qreal,qreal);
	BIND_PAINTER_PROCEDURE_2(translate,qreal,qreal);

	BIND_PAINTER_FUNCTION_0(bool, hasClipping);
	BIND_PAINTER_FUNCTION_0(bool, isActive);
	BIND_PAINTER_FUNCTION_0(qreal, opacity);
	BIND_PAINTER_FUNCTION_0(bool, viewTransformEnabled);
	BIND_PAINTER_FUNCTION_0(bool,worldMatrixEnabled);
}
