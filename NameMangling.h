#ifndef NAMEMANGLING_H
#define NAMEMANGLING_H

#include <QtCore/QList>

class Expression;

class NameMangling
{
public:
	NameMangling();

	static QString mangleFunctionName(const QString &functionName, const QList<int> &parametersTypes);

	static QString mangleFunctionName(const QString &functionName, const QList<Expression*> &expressionList);
};

#endif
