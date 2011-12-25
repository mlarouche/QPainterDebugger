#ifndef VARIABLECREATION_H
#define VARIABLECREATION_H

#include "ASTNode.h"

class Expression;

class VariableCreation : public ASTNode
{
public:
	VariableCreation(const QString& variableName, Expression* expression, Scope* context);
	virtual ~VariableCreation();

	virtual QVariant evaluate();

private:
	QString m_variableName;
	Expression* m_expression;
};

#endif
