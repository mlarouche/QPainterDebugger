#ifndef PAINTERCOMMAND_H
#define PAINTERCOMMAND_H

#include <QtCore/QList>
#include <QtGui/QPainter>

class Expression;

class PainterCommand
{
public:
	PainterCommand();
	virtual ~PainterCommand();

	virtual QVariant execute(QPainter* painter, const QList<Expression*>& parameters) = 0;
};

#endif
