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

protected:
	PainterContext* context() const
	{
		return m_context;
	}

private:
	PainterContext* m_context;
};

#endif
