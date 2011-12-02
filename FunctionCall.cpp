#include "FunctionCall.h"

#include "Expression.h"

// TEMP
#include "DrawTextCommand.h"

FunctionCall::FunctionCall(const QString &functionName, PainterContext* context)
: ASTNode(context), m_functionName(functionName)
{
}

void FunctionCall::addParameter(Expression* expression)
{
	m_parameters.append(expression);
}

QVariant FunctionCall::evaluate()
{
	if(context()->isValidFunction(m_functionName))
	{
		context()->function(m_functionName)->execute(context()->painter(), m_parameters);
	}

	return QVariant();
}
