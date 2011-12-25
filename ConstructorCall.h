#ifndef CONSTRUCTORCALL_H
#define CONSTRUCTORCALL_H

#include "FunctionCall.h"

#include <QtCore/QList>

class ConstructorCall : public FunctionCall
{
public:
	ConstructorCall(const QString &className, Scope *context);
	~ConstructorCall();

	QVariant evaluate();
};

#endif
