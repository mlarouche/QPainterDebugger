#include "FunctionCall.h"

// Local includes
#include "Expression.h"
#include "PainterCommand.h"
#include "PainterContext.h"
#include "NameMangling.h"

FunctionCall::FunctionCall(const QString &functionName, PainterContext* context)
: Expression(context), m_functionName(functionName)
{
}

FunctionCall::~FunctionCall()
{
	qDeleteAll(m_parameters);
}

QVariant::Type FunctionCall::type() const
{
	return QVariant::UserType;
}

void FunctionCall::addParameter(Expression* expression)
{
	m_parameters.append(expression);
}

QVariant FunctionCall::evaluate()
{
	QVariant returnValue;

	PainterContext* painterContext = static_cast<PainterContext*>(context());
	if(painterContext->isValidFunction(m_functionName))
	{
		returnValue = painterContext->function(m_functionName)->execute(painterContext->painter(), m_parameters);
	}
	else
	{
		showErrorMessage(QString("%1 is not a valid function name").arg(m_functionName));
	}

	return returnValue;
}
