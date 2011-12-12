#include "ASTNode.h"

#include <QtGui/QMessageBox>

ASTNode::ASTNode()
: m_context(0)
{
}

ASTNode::~ASTNode()
{
}

void ASTNode::showErrorMessage(const QString &message)
{
	QMessageBox::critical(0, "Runtime Error", message);
}
