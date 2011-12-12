#ifndef ASTNODE_H
#define ASTNODE_H

#include <QtCore/QVariant>

#include "PainterContext.h"

class ASTNode
{
public:
	ASTNode();
	virtual ~ASTNode();

	ASTNode(PainterContext* context)
	{
		setContext(context);
	}

	void setContext(PainterContext* context)
	{
		m_context = context;
	}

	virtual QVariant evaluate() = 0;

protected:
	PainterContext* context() const
	{
		return m_context;
	}

	void showErrorMessage(const QString& message);

private:
	PainterContext* m_context;
	QString m_errorMessage;
};

#endif
