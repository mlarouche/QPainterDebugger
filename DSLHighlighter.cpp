#include "DSLHighlighter.h"

DSLHighlighter::DSLHighlighter(QTextDocument* document)
: QSyntaxHighlighter(document)
{
	setupHighlighter();
}

void DSLHighlighter::setupHighlighter()
{
	keywordFormat.setForeground(Qt::blue);
	keywordFormat.setFontWeight(QFont::Bold);

	QStringList keywordPatterns;
	keywordPatterns << "\\bvar\\b" << "\\btrue\\b" << "\\bfalse\\b";

	HighlightingRule rule;
	foreach(const QString &pattern, keywordPatterns)
	{
		rule.pattern = QRegExp(pattern);
		rule.format = keywordFormat;
		highlightingRules.append(rule);
	}

	quotationFormat.setForeground(Qt::darkGreen);
	rule.pattern = QRegExp("\".*\"");
	rule.format = quotationFormat;
	highlightingRules.append(rule);

	functionFormat.setForeground(Qt::red);
	rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
	rule.format = functionFormat;
	highlightingRules.append(rule);

	numericFormat.setForeground(Qt::darkMagenta);
	numericFormat.setFontWeight(QFont::Bold);
	rule.pattern = QRegExp("\\b[0-9]+(.[0-9]+)?\\b");
	rule.format = numericFormat;
	highlightingRules.append(rule);
}

void DSLHighlighter::highlightBlock(const QString &text)
{
	foreach(const HighlightingRule &rule, highlightingRules)
	{
		QRegExp expression(rule.pattern);
		int index = expression.indexIn(text);
		while(index >= 0)
		{
			int length = expression.matchedLength();
			setFormat(index, length, rule.format);
			index = expression.indexIn(text, index + length);
		}
	}
}
