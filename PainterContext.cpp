#include "PainterContext.h"

#include "PainterCommand.h"

#include "Expression.h"

PainterContext::PainterContext()
{
	bindEnums();
	bindFunctions();
}

PainterContext::~PainterContext()
{
	qDeleteAll(m_functions);
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

void PainterContext::bindEnums()
{
	BEGIN_BIND_ENUM(GlobalColor)
		ENUM_NAME_VALUE(white, Qt::white);
		ENUM_NAME_VALUE(black, Qt::black);
		ENUM_NAME_VALUE(red, Qt::red);
		ENUM_NAME_VALUE(darkRed, Qt::darkRed);
		ENUM_NAME_VALUE(green, Qt::green);
		ENUM_NAME_VALUE(darkGreen, Qt::darkGreen);
		ENUM_NAME_VALUE(blue, Qt::blue);
		ENUM_NAME_VALUE(darkBlue, Qt::darkBlue);
		ENUM_NAME_VALUE(cyan, Qt::cyan);
		ENUM_NAME_VALUE(darkCyan, Qt::darkCyan);
		ENUM_NAME_VALUE(magenta, Qt::magenta);
		ENUM_NAME_VALUE(darkMagenta, Qt::darkMagenta);
		ENUM_NAME_VALUE(yellow, Qt::yellow);
		ENUM_NAME_VALUE(darkYellow, Qt::darkYellow);
		ENUM_NAME_VALUE(gray, Qt::gray);
		ENUM_NAME_VALUE(darkGray, Qt::darkGray);
		ENUM_NAME_VALUE(lightGray, Qt::lightGray);
		ENUM_NAME_VALUE(transparent, Qt::transparent);
		ENUM_NAME_VALUE(color0, Qt::color0);
		ENUM_NAME_VALUE(color1, Qt::color1);
	END_BIND_ENUM(GlobalColor)
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
	BIND_PAINTER_PROCEDURE_1(setPen, QColor);

	BIND_PAINTER_FUNCTION_0(bool, hasClipping);
	BIND_PAINTER_FUNCTION_0(bool, isActive);
	BIND_PAINTER_FUNCTION_0(qreal, opacity);
	BIND_PAINTER_FUNCTION_0(bool, viewTransformEnabled);
	BIND_PAINTER_FUNCTION_0(bool,worldMatrixEnabled);
}
