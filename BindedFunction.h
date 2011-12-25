#ifndef BINDEDFUNCTION_H
#define BINDEDFUNCTION_H

#include <QtCore/QList>
#include <QtCore/QVariant>

class Expression;

template<class T>
class BindedFunction
{
public:
	BindedFunction()
	{}

	virtual QVariant execute(T*, const QList<Expression*> &)
	{
		return QVariant();
	}
};

#endif
