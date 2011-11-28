#ifndef DRAWTEXTCOMMAND_H
#define DRAWTEXTCOMMAND_H

#include <QtCore/QList>

#include "PainterCommand.h"
#include "Expression.h"

class DrawTextCommand : public PainterCommand
{
public:
    DrawTextCommand();

	QList<Expression>	arguments;

	virtual void execute(QPainter *painter);
};

#endif // DRAWTEXTCOMMAND_H
