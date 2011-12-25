#ifndef PAINTERCONTEXT_H
#define PAINTERCONTEXT_H

#include "BindedFunction.h"
#include "ClassScope.h"

class QPainter;

class PainterContext : public ClassScope<QPainter>
{
public:
	PainterContext();
	~PainterContext();

	void setPainter(QPainter* painter)
	{
		m_classInstance = painter;
	}

private:
	void bindEnums();
	void bindQColor();
};

class PainterClassPrototype : public ClassPrototype<QPainter>
{
public:
	PainterClassPrototype();
};

#endif
