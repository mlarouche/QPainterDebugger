#ifndef FUNCTIONCALL
#define FUNCTIONCALL

#include "Expression.h"

#include <QtCore/QList>

class PainterContext;

class FunctionCall : public Expression
{
public:
	FunctionCall(const QString &functionName, Scope* scope);
	virtual ~FunctionCall();

	virtual QVariant::Type type() const;

	virtual QVariant evaluate();

	void addParameter(Expression* expression);

protected:
	QString m_functionName;
	QList<Expression*> m_parameters;
};

#endif
