#ifndef FUNCTIONCALL
#define FUNCTIONCALL

#include "Expression.h"

#include <QtCore/QList>

class FunctionCall : public Expression
{
public:
	FunctionCall(const QString &functionName, PainterContext* context);
	virtual ~FunctionCall();

	QVariant::Type type() const;

	QVariant evaluate();

	void addParameter(Expression* expression);

private:
	QString m_functionName;
	QList<Expression*> m_parameters;
};

#endif
