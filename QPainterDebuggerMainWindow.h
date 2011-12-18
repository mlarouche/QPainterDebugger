#ifndef QPAINTERDEBUGGERMAINWINDOW_H
#define QPAINTERDEBUGGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
	class QPainterDebuggerMainWindow;
}

class DSLHighlighter;

class QPainterDebuggerMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit QPainterDebuggerMainWindow(QWidget *parent = 0);
	~QPainterDebuggerMainWindow();

private slots:
	void buttonDebug_Clicked();

private:
	void connectSlots();

private:
	Ui::QPainterDebuggerMainWindow *ui;
	DSLHighlighter* m_highlighter;
};

#endif
