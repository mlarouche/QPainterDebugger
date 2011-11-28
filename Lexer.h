#ifndef LEXER_H
#define LEXER_H

#include <QtCore/QString>
#include <QtCore/QVariant>

class Lexer
{
public:
	enum Token
	{
		Invalid = 0,
		Identifier,
		StringLiteral,
		NumberLiteral,
		LeftParenthesis,
		RightParenthesis,
		Comma
	};

public:
	Lexer(const QString &sourceText);

	Token getNextToken();

	QVariant lastReadValue() const { return m_lastValue; }

private:
	QChar consumeChar();

private:
	QString m_sourceText;
	QVariant m_lastValue;
	quint32 m_charIndex;
	QChar m_lastChar;
};

#endif
