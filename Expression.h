#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QtCore/QVariant>

class Expression
{
public:
	Expression();

	virtual QVariant evaluate() = 0;
};

#endif
