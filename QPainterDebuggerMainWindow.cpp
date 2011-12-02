#include "QPainterDebuggerMainWindow.h"
#include "ui_QPainterDebuggerMainWindow.h"

// Qt includes
#include <QtGui/QMessageBox>
#include <QtGui/QPainter>

// Local includess
#include "Lexer.h"
#include "Parser.h"
#include "PainterContext.h"
#include "DrawTextCommand.h"

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
	QImage resultImage(ui->labelGraphicPreview->width(),ui->labelGraphicPreview->height(), QImage::Format_ARGB32);
	resultImage.fill(0);
	QPainter painter(&resultImage);

	QString readCode = ui->textEditCode->toPlainText();

	PainterContext context;
	context.setVariable("boba", 6667);
	context.setPainter(&painter);
	context.setFunction("drawText", new DrawTextCommand);

	Parser parser;
	parser.setContext(&context);

	ASTNode* rootNode = parser.parse(readCode);

	if(rootNode)
	{
		rootNode->evaluate();

		ui->labelGraphicPreview->setPixmap(QPixmap::fromImage(resultImage));
	}
}
