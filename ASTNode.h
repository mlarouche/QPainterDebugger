#ifndef ASTNODE_H
#define ASTNODE_H

#include <QtCore/QVariant>

#include "PainterContext.h"

class ASTNode
{
public:
	ASTNode();

	ASTNode(PainterContext* context)
	{
		setContext(context);
	}

	void setContext(PainterContext* context)
	{
		m_context = context;
	}

	virtual QVariant evaluate() = 0;

	bool hasError() const
	{
		return !m_errorMessage.isEmpty();
	}

	QString errorMessage() const
	{
		return m_errorMessage;
	}

protected:
	PainterContext* context() const
	{
		return m_context;
	}

	void setErrorMessage(const QString& message)
	{
		m_errorMessage = message;
	}

private:
	PainterContext* m_context;
	QString m_errorMessage;
};

#endif
