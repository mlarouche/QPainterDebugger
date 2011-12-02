#ifndef DRAWTEXTCOMMAND_H
#define DRAWTEXTCOMMAND_H

#include <QtCore/QList>

#include "PainterCommand.h"
#include "Expression.h"

class DrawTextCommand : public PainterCommand
{
public:
	DrawTextCommand();

	virtual void execute(QPainter *painter, const QList<Expression*> parameters);
};

#endif
