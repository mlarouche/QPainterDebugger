#ifndef DSLHIGHLIGHTER_H
#define DSLHIGHLIGHTER_H

#include <QtCore/QVector>
#include <QtGui/QSyntaxHighlighter>

class DSLHighlighter : public QSyntaxHighlighter
{
	Q_OBJECT
public:
	explicit DSLHighlighter(QTextDocument* document);

protected:
	void highlightBlock(const QString &text);

private:
	void setupHighlighter();

private:
	struct HighlightingRule
	{
		QRegExp pattern;
		QTextCharFormat format;
	};
	QVector<HighlightingRule> highlightingRules;

	QTextCharFormat keywordFormat;
	QTextCharFormat quotationFormat;
	QTextCharFormat functionFormat;
	QTextCharFormat numericFormat;
};

#endif
