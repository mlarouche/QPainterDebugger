#ifndef PAINTERCOMMAND_H
#define PAINTERCOMMAND_H

#include <QtGui/QPainter>

class PainterCommand
{
public:
	PainterCommand();

	virtual void execute(QPainter* painter) = 0;
};

#endif
