#ifndef PAINTERCOMMAND_H
#define PAINTERCOMMAND_H

#include <QtCore/QList>
#include <QtGui/QPainter>

class Expression;

class PainterCommand
{
public:
	PainterCommand();

	virtual void execute(QPainter* painter, const QList<Expression*> parameters) = 0;
};

#endif