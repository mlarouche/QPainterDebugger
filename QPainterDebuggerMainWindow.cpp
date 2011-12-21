#include "QPainterDebuggerMainWindow.h"
#include "ui_QPainterDebuggerMainWindow.h"

// Qt includes
#include <QtGui/QMessageBox>
#include <QtGui/QPainter>

// Local includess
#include "DSLHighlighter.h"
#include "Lexer.h"
#include "Parser.h"
#include "PainterContext.h"

QPainterDebuggerMainWindow::QPainterDebuggerMainWindow(QWidget *parent)
: QMainWindow(parent),ui(new Ui::QPainterDebuggerMainWindow)
{
	ui->setupUi(this);

	connectSlots();

	m_highlighter = new DSLHighlighter(ui->textEditCode->document());
}

QPainterDebuggerMainWindow::~QPainterDebuggerMainWindow()
{
	delete ui;
	delete m_highlighter;
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

	Scope *thisScope = new Scope;

	Scope* pointScope = new Scope;
	pointScope->setVariable("x", 10);
	pointScope->setVariable("y", "25");
	thisScope->addScope("Point", pointScope);

	PainterContext context;
	context.setPainter(&painter);
	context.addScope("this", thisScope);

	Parser parser;
	parser.setContext(&context);

	ASTNode* rootNode = parser.parse(readCode);

	if(parser.hasError())
	{
		QMessageBox::critical(this, "Parsing error", parser.errorMessage());
		return;
	}

	if(rootNode)
	{
		rootNode->evaluate();

		ui->labelGraphicPreview->setPixmap(QPixmap::fromImage(resultImage));
	}

	delete rootNode;
}
