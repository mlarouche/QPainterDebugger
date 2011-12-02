#ifndef ROOTNODE_H
#define ROOTNODE_H

#include "ASTNode.h"

#include <QtCore/QList>

class RootNode : public ASTNode
{
public:
	RootNode();

	virtual QVariant evaluate();

	void addChild(ASTNode* child);

private:
	QList<ASTNode*> m_children;
};

#endif
