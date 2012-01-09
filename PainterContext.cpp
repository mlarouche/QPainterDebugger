#include "PainterContext.h"

//Qt includes
#include <QtGui/QColor>
#include <QtGui/QPainter>

// Local includes
#include "BindingMacros.h"
#include "ClassConstructor.h"
#include "ClassScope.h"
#include "Expression.h"

template<>
QVariant ClassScope<QPainter>::asQVariant() const
{
	return QVariant();
}

PainterContext::PainterContext()
	: ClassScope<QPainter>(new PainterClassPrototype)
{
	bindEnums();

	bindQColor();
}

PainterContext::~PainterContext()
{
	m_classInstance = 0;
	delete m_prototype;
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

void PainterContext::bindQColor()
{
	BEGIN_BIND_CLASS(QColor)
		BIND_CLASS_FUNCTION_0(QColor,int,alpha);
		BIND_CLASS_FUNCTION_0(QColor,double,alphaF);
		BIND_CLASS_FUNCTION_0(QColor,int,black);
		BIND_CLASS_FUNCTION_0(QColor,double,blackF);
		BIND_CLASS_FUNCTION_0(QColor,int,blue);
		BIND_CLASS_FUNCTION_0(QColor,double,blueF);
		//BIND_CLASS_FUNCTION_1(QColor,QColor,convertTo,int);
		BIND_CLASS_FUNCTION_0(QColor,int,cyan);
		BIND_CLASS_FUNCTION_0(QColor,double,cyanF);
		BIND_CLASS_FUNCTION_1(QColor,QColor,darker,int);
		BIND_CLASS_FUNCTION_0(QColor,int,green);
		BIND_CLASS_FUNCTION_0(QColor,double,greenF);
		BIND_CLASS_FUNCTION_0(QColor,int,hslHue);
		BIND_CLASS_FUNCTION_0(QColor,double,hslHueF);
		BIND_CLASS_FUNCTION_0(QColor,int,hslSaturation);
		BIND_CLASS_FUNCTION_0(QColor,double,hslSaturationF);
		BIND_CLASS_FUNCTION_0(QColor,int,hsvHue);
		BIND_CLASS_FUNCTION_0(QColor,double,hsvHueF);
		BIND_CLASS_FUNCTION_0(QColor,int,hsvSaturation);
		BIND_CLASS_FUNCTION_0(QColor,double,hsvSaturationF);
		BIND_CLASS_FUNCTION_0(QColor,int,hue);
		BIND_CLASS_FUNCTION_0(QColor,double,hueF);
		BIND_CLASS_FUNCTION_0(QColor,bool,isValid);
		BIND_CLASS_FUNCTION_1(QColor,QColor,lighter,int);
		BIND_CLASS_FUNCTION_0(QColor,int,lightness);
		BIND_CLASS_FUNCTION_0(QColor,double,lightnessF);
		BIND_CLASS_FUNCTION_0(QColor,int,magenta);
		BIND_CLASS_FUNCTION_0(QColor,double,magentaF);
		BIND_CLASS_FUNCTION_0(QColor,QString,name);
		BIND_CLASS_FUNCTION_0(QColor,int,red);
		BIND_CLASS_FUNCTION_0(QColor,double,redF);
		BIND_CLASS_FUNCTION_0(QColor,QRgb,rgb);
		BIND_CLASS_FUNCTION_0(QColor,QRgb,rgba);
		BIND_CLASS_FUNCTION_0(QColor,int,saturation);
		BIND_CLASS_FUNCTION_0(QColor,double,saturationF);
		BIND_CLASS_PROCEDURE_1(QColor,setAlpha,int);
		BIND_CLASS_PROCEDURE_1(QColor,setAlphaF,double);
		BIND_CLASS_PROCEDURE_1(QColor,setBlue,int);
		BIND_CLASS_PROCEDURE_1(QColor,setBlueF,double);
		BIND_CLASS_PROCEDURE_5(QColor,setCmyk,int,int,int,int,int);
		BIND_CLASS_PROCEDURE_5(QColor,setCmykF,double,double,double,double,double);
		BIND_CLASS_PROCEDURE_1(QColor,setGreen,int);
		BIND_CLASS_PROCEDURE_1(QColor,setGreenF,double);
		BIND_CLASS_PROCEDURE_4(QColor,setHsl,int,int,int,int);
		BIND_CLASS_PROCEDURE_4(QColor,setHslF,double,double,double,double);
		BIND_CLASS_PROCEDURE_4(QColor,setHsv,int,int,int,int);
		BIND_CLASS_PROCEDURE_4(QColor,setHsvF,double,double,double,double);
		BIND_CLASS_PROCEDURE_1(QColor,setNamedColor,QString);
		BIND_CLASS_PROCEDURE_1(QColor,setRed,int);
		BIND_CLASS_PROCEDURE_1(QColor,setRedF,double);
		BIND_CLASS_PROCEDURE_4(QColor,setRgb,int,int,int,int);
		BIND_CLASS_PROCEDURE_1(QColor,setRgb,int); // Add it when overload are supported
		BIND_CLASS_PROCEDURE_4(QColor,setRgbF,double,double,double,double);
		BIND_CLASS_PROCEDURE_1(QColor,setRgba,int);
		BIND_CLASS_FUNCTION_0(QColor,int,spec);
		BIND_CLASS_FUNCTION_0(QColor,QColor,toCmyk);
		BIND_CLASS_FUNCTION_0(QColor,QColor,toHsl);
		BIND_CLASS_FUNCTION_0(QColor,QColor,toHsv);
		BIND_CLASS_FUNCTION_0(QColor,QColor,toRgb);
		BIND_CLASS_FUNCTION_0(QColor,int,value);
		BIND_CLASS_FUNCTION_0(QColor,double,valueF);
		BIND_CLASS_FUNCTION_0(QColor,int,yellow);
		BIND_CLASS_FUNCTION_0(QColor,double,yellowF);
	END_BIND_CLASS(QColor)

	BIND_CLASS_CONSTRUCTOR_0(QColor);
	BIND_CLASS_CONSTRUCTOR_1(QColor,int);
	BIND_CLASS_CONSTRUCTOR_1(QColor,QString);
	BIND_CLASS_CONSTRUCTOR_3(QColor,int,int,int);
}

PainterClassPrototype::PainterClassPrototype()
: ClassPrototype<QPainter>()
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
	BIND_PAINTER_PROCEDURE_1(rotate,double);
	BIND_PAINTER_PROCEDURE_0(save);
	BIND_PAINTER_PROCEDURE_2(scale,double,double);
	BIND_PAINTER_PROCEDURE_2(setBrushOrigin,int,int);
	BIND_PAINTER_PROCEDURE_1(setClipping,bool);
	BIND_PAINTER_PROCEDURE_1(setOpacity,double);
	BIND_PAINTER_PROCEDURE_1(setViewTransformEnabled,bool);
	BIND_PAINTER_PROCEDURE_2(shear, double,double);
	BIND_PAINTER_PROCEDURE_2(translate,double,double);
	BIND_PAINTER_PROCEDURE_1(setPen, QColor);

	BIND_PAINTER_PROCEDURE_5(fillRect,int,int,int,int,QColor);
	BIND_PAINTER_PROCEDURE_5(fillRect,int,int,int,int,int);

	BIND_PAINTER_FUNCTION_0(bool,hasClipping);
	BIND_PAINTER_FUNCTION_0(bool,isActive);
	BIND_PAINTER_FUNCTION_0(double,opacity);
	BIND_PAINTER_FUNCTION_0(bool,viewTransformEnabled);
	BIND_PAINTER_FUNCTION_0(bool,worldMatrixEnabled);
}
