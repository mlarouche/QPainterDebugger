#include "DrawTextCommand.h"

DrawTextCommand::DrawTextCommand()
: PainterCommand()
{
}

void DrawTextCommand::execute(QPainter* painter, const QList<Expression*> parameters)
{
	painter->drawText(parameters[0]->evaluate().toInt(), parameters[1]->evaluate().toInt(), parameters[2]->evaluate().toString());
}
