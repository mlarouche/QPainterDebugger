#include "VariableCreation.h"

#include "Expression.h"

VariableCreation::VariableCreation(const QString& variableName, Expression* expression, Scope* context)
: ASTNode(context), m_variableName(variableName), m_expression(expression)
{
}

VariableCreation::~VariableCreation()
{
	delete m_expression;
}

QVariant VariableCreation::evaluate()
{
	QVariant expressionValue = m_expression->evaluate();
	if(expressionValue.canConvert<ClassInstance>())
	{
		if(context()->hasScope(m_variableName) || context()->hasVariable(m_variableName))
		{
			showErrorMessage(QString("Variable %1 is already defined").arg(m_variableName));
			return QVariant();
		}

		ClassInstance instance = expressionValue.value<ClassInstance>();
		context()->addScope(m_variableName, instance.classInstance);
	}
	else
	{
		if(context()->hasScope(m_variableName) || context()->hasVariable(m_variableName))
		{
			showErrorMessage(QString("Variable %1 is already defined").arg(m_variableName));
			return QVariant();
		}

		context()->setVariable(m_variableName, m_expression->evaluate());
	}
	return QVariant();
}
