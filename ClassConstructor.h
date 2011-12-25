#ifndef CLASSCONSTRUCTOR_H
#define CLASSCONSTRUCTOR_H

#include <QtCore/QList>

class Expression;
class Scope;

class ClassConstructor
{
public:
	virtual Scope* create(Scope *context, const QList<Expression*> &parameters) = 0;
};

#endif
