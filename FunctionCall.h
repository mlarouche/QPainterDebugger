#ifndef FUNCTIONCALL
#define FUNCTIONCALL

#include "ASTNode.h"

#include <QtCore/QList>

class Expression;

class FunctionCall : public ASTNode
{
public:
	FunctionCall(const QString &functionName, PainterContext* context);
	~FunctionCall();

	virtual QVariant evaluate();

	void addParameter(Expression* expression);

private:
	QString m_functionName;
	QList<Expression*> m_parameters;
};

#endif
