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
	context()->setVariable(m_variableName, m_expression->evaluate());
	return QVariant();
}
