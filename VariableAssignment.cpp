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
	Scope* scopeToUse = 0;
	QString variableName = context()->findIdentifierAndScope(m_variableName,scopeToUse);

	QVariant expressionValue = m_expression->evaluate();
	if(expressionValue.canConvert<ClassInstance>())
	{
		if(!scopeToUse->hasScope(variableName))
		{
			showErrorMessage(QString("Scope %1 does not exists for assignment").arg(variableName));
			return QVariant();
		}

		ClassInstance instance = expressionValue.value<ClassInstance>();
		scopeToUse->addScope(variableName, instance.classInstance);
	}
	else
	{
		if(!scopeToUse->hasVariable(variableName))
		{
			showErrorMessage(QString("Variable %1 is not definied in assignment context").arg(variableName));
			return QVariant();
		}

		scopeToUse->setVariable(variableName, m_expression->evaluate());
	}

	return QVariant();
}
