#include "QPainterDebuggerMainWindow.h"
#include "ui_QPainterDebuggerMainWindow.h"

// Qt includes
#include <QtGui/QMessageBox>

// Local includess
#include "Lexer.h"

QPainterDebuggerMainWindow::QPainterDebuggerMainWindow(QWidget *parent)
: QMainWindow(parent),ui(new Ui::QPainterDebuggerMainWindow)
{
	ui->setupUi(this);

	connectSlots();
}

QPainterDebuggerMainWindow::~QPainterDebuggerMainWindow()
{
	delete ui;
}

void QPainterDebuggerMainWindow::connectSlots()
{
	connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(ui->buttonDebug, SIGNAL(clicked()), this, SLOT(buttonDebug_Clicked()));
}

void QPainterDebuggerMainWindow::buttonDebug_Clicked()
{
	QString readCode = ui->textEditCode->toPlainText();

	Lexer lexer(readCode);

	Lexer::Token token = lexer.getNextToken();
	while(token != Lexer::Invalid)
	{
		QMessageBox::information(this, "DEBUG", QString("Type=%1,Value=%2").arg(token).arg(lexer.lastReadValue().toString()));
		token = lexer.getNextToken();
	}
}
