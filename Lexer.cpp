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
		qDebug("NUMBER_LITERAL");

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
		qDebug("STRING_LITERAL");

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
		qDebug("LEFT_PARENTHESIS");
		m_lastChar = consumeChar();
		return Lexer::LeftParenthesis;
	}
	else if(m_lastChar == ')')
	{
		qDebug("RIGHT_PARENTHESIS");
		m_lastChar = consumeChar();
		return Lexer::RightParenthesis;
	}
	else if(m_lastChar == ',')
	{
		qDebug("COMMA");
		m_lastChar = consumeChar();
		return Lexer::Comma;
	}
	else if(m_lastChar.isLetter())
	{
		qDebug("IDENTIFIER");

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
	else
	{
		if (m_charIndex == -1)
		{
			qDebug("EOF");
			return Lexer::EndOfFile;
		}

		qDebug("Invalid token found !");
		return Lexer::Invalid;
	}
}

Lexer::Token Lexer::lookAhead()
{
	QVariant tempLastValue = m_lastValue;
	quint32 tempCharIndex = m_charIndex;
	QChar tempLastChar = m_lastChar;

	Lexer::Token token = getNextToken();

	m_lastValue = tempLastValue;
	m_charIndex = tempCharIndex;
	m_lastChar = tempLastChar;

	return token;
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

