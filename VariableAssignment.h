#ifndef VARIABLEASSIGNMENT_H
#define VARIABLEASSIGNMENT_H

#include "ASTNode.h"

class Expression;

class VariableAssignment : public ASTNode
{
public:
	VariableAssignment(const QString& variableName, Expression* expression, PainterContext* context);
	virtual ~VariableAssignment();

	virtual QVariant evaluate();

private:
	QString m_variableName;
	Expression* m_expression;
};

#endif
