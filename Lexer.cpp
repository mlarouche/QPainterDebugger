#include "Lexer.h"

Lexer::Lexer(const QString &sourceText)
: m_sourceText(sourceText), m_charIndex(0), m_lastChar(' ')
{
}

Lexer::Token Lexer::getNextToken()
{
	while(m_lastChar.isSpace())
	{
		m_lastChar = consumeChar();
	}

	if(m_lastChar.isDigit())
	{
		qDebug("NumberLiteral");

		QString numberLiteral;

		do
		{
			numberLiteral += m_lastChar;
			m_lastChar = consumeChar();
		}
		while(m_lastChar.isDigit());

		m_lastValue = numberLiteral;
		return Lexer::NumberLiteral;
	}
	else if(m_lastChar == '"')
	{
		qDebug("StringLiteral");

		m_lastChar = consumeChar();

		QString stringLiteral;
		do
		{
			stringLiteral += m_lastChar;
			m_lastChar = consumeChar();
		}
		while(m_lastChar != '"');
		m_lastChar = consumeChar();

		m_lastValue = stringLiteral;
		return Lexer::StringLiteral;
	}
	else if(m_lastChar == '(')
	{
		qDebug("LeftParenthesis");
		m_lastChar = consumeChar();
		return Lexer::LeftParenthesis;
	}
	else if(m_lastChar == ')')
	{
		qDebug("RightParenthesis");
		m_lastChar = consumeChar();
		return Lexer::RightParenthesis;
	}
	else if(m_lastChar == ',')
	{
		qDebug("Comma");
		m_lastChar = consumeChar();
		return Lexer::Comma;
	}
	else if(m_lastChar.isLetter())
	{
		qDebug("Identifier");

		QString identifier;

		do
		{
			identifier += m_lastChar;
			m_lastChar = consumeChar();
		}
		while(m_lastChar.isLetterOrNumber());

		m_lastValue = identifier;
		return Lexer::Identifier;
	}

	return Lexer::Invalid;
}

QChar Lexer::consumeChar()
{
	if(m_charIndex == -1)
	{
		return QChar();
	}

	QChar readChar = m_sourceText[m_charIndex];
	m_charIndex++;

	if( m_charIndex > m_sourceText.length() )
	{
		m_charIndex = -1;
		return QChar();
	}

	return readChar;
}

