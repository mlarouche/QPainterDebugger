#ifndef ASTNODE_H
#define ASTNODE_H

#include <QtCore/QVariant>

#include "Scope.h"

class ASTNode
{
public:
	ASTNode();
	virtual ~ASTNode();

	ASTNode(Scope* context)
	{
		setContext(context);
	}

	void setContext(Scope* context)
	{
		m_context = context;
	}

	virtual QVariant evaluate() = 0;

protected:
	Scope* context() const
	{
		return m_context;
	}

	void showErrorMessage(const QString& message);

private:
	Scope* m_context;
	QString m_errorMessage;
};

#endif
