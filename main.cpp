#include <QtGui/QApplication>
#include "QPainterDebuggerMainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPainterDebuggerMainWindow w;
	w.show();

	return a.exec();
}
