#include "FunctionCall.h"

#include "Expression.h"
#include "PainterCommand.h"

FunctionCall::FunctionCall(const QString &functionName, PainterContext* context)
: ASTNode(context), m_functionName(functionName)
{
}

FunctionCall::~FunctionCall()
{
	qDeleteAll(m_parameters);
}

void FunctionCall::addParameter(Expression* expression)
{
	m_parameters.append(expression);
}

QVariant FunctionCall::evaluate()
{
	QVariant returnValue;

	if(context()->isValidFunction(m_functionName))
	{
		returnValue = context()->function(m_functionName)->execute(context()->painter(), m_parameters);
	}
	else
	{
		showErrorMessage(QString("%1 is not a valid function name").arg(m_functionName));
	}

	return returnValue;
}
