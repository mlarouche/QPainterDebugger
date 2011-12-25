#include "VariableAssignment.h"

#include "Expression.h"

VariableAssignment::VariableAssignment(const QString& variableName, Expression* expression, Scope* context)
: ASTNode(context), m_variableName(variableName), m_expression(expression)
{
}

VariableAssignment::~VariableAssignment()
{
	delete m_expression;
}

QVariant VariableAssignment::evaluate()
{
	QVariant expressionValue = m_expression->evaluate();
	if(expressionValue.canConvert<ClassInstance>())
	{
		ClassInstance instance = expressionValue.value<ClassInstance>();
		context()->addScope(m_variableName, instance.classInstance);
	}
	else
	{
		context()->setVariable(m_variableName, m_expression->evaluate());
	}
	return QVariant();
}
