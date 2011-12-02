#include "RootNode.h"

RootNode::RootNode()
: ASTNode()
{
}

void RootNode::addChild(ASTNode *child)
{
	m_children.append(child);
}

QVariant RootNode::evaluate()
{
	QVariant lastReturnValue;

	foreach(ASTNode* child, m_children)
	{
		lastReturnValue = child->evaluate();
	}

	return lastReturnValue;
}
