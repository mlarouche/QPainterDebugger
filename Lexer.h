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
		EndOfFile,
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

	Token lookAhead();

	int currentLine() const
	{
		return m_currentLine;
	}

	int currentColumn() const
	{
		return m_currentColumn;
	}

private:
	QChar consumeChar();

private:
	QString m_sourceText;
	QVariant m_lastValue;
	quint32 m_charIndex;
	QChar m_lastChar;
	int m_currentLine;
	int m_currentColumn;
};

#endif
