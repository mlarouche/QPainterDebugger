#include "FunctionCall.h"

// Local includes
#include "Expression.h"
#include "PainterContext.h"
#include "NameMangling.h"

FunctionCall::FunctionCall(const QString &functionName, Scope* context)
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
	Scope* scopeToUse;
	QString functionName = context()->findIdentifierAndScope(m_functionName, scopeToUse);

	QVariant returnValue;

	if(scopeToUse->isValidFunction(functionName))
	{
		returnValue = scopeToUse->execute(functionName, m_parameters);
	}
	else
	{
		showErrorMessage(QString("%1 is not a valid function name").arg(functionName));
	}

	return returnValue;
}
