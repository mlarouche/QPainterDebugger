#include "Lexer.h"

struct KeywordPair
{
	const char* keyword;
	Lexer::Token token;
};

KeywordPair Keywords[] = {
	{"var", Lexer::Keyword_var}
};

Lexer::Lexer(const QString &sourceText)
	: m_sourceText(sourceText), m_charIndex(0), m_lastChar(' '), m_currentLine(0), m_currentColumn(0)
{
}

Lexer::Token Lexer::getNextToken()
{
	while(m_lastChar.isSpace())
	{
		if(m_lastChar == '\n')
		{
			m_currentLine++;
			m_currentColumn = 0;
		}
		consumeChar();
	}

	if(m_lastChar.isDigit())
	{
		qDebug("NUMBER_LITERAL");

		QString numberLiteral;

		do
		{
			numberLiteral += m_lastChar;
			consumeChar();
		}
		while(m_lastChar.isDigit());

		m_lastValue = numberLiteral;
		return Lexer::NumberLiteral;
	}
	else if(m_lastChar == '"')
	{
		qDebug("STRING_LITERAL");

		consumeChar();

		QString stringLiteral;
		do
		{
			stringLiteral += m_lastChar;
			consumeChar();
		}
		while(m_lastChar != '"');
		consumeChar();

		m_lastValue = stringLiteral;
		return Lexer::StringLiteral;
	}
	else if(m_lastChar.isLetter())
	{
		QString identifier;

		do
		{
			identifier += m_lastChar;

			Lexer::Token keyword = isKeyword(identifier);
			if(keyword != Lexer::Invalid)
			{
				qDebug("KEYWORD");
				consumeChar();
				return keyword;
			}

			consumeChar();
		}
		while(m_lastChar.isLetterOrNumber());

		qDebug("IDENTIFIER");
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

		Lexer::Token token;

		switch(m_lastChar.toLatin1())
		{
			case '(':
				qDebug("LEFT_PARENTHESIS");
				token = Lexer::LeftParenthesis;
				break;
			case ')':
				qDebug("RIGHT_PARENTHESIS");
				token = Lexer::RightParenthesis;
				break;
			case ',':
				qDebug("COMMA");
				token = Lexer::Comma;
				break;
			case '=':
				qDebug("EQUAL_SIGN");
				token = Lexer::EqualSign;
				break;
			default:
				qDebug("Invalid token found !");
				token = Lexer::Invalid;
				break;
		}

		consumeChar();
		return token;
	}
}

Lexer::Token Lexer::lookAhead()
{
	QVariant tempLastValue = m_lastValue;
	quint32 tempCharIndex = m_charIndex;
	QChar tempLastChar = m_lastChar;
	int tempCurrentLine = m_currentLine;
	int tempCurrentColumn = m_currentColumn;

	Lexer::Token token = getNextToken();

	m_lastValue = tempLastValue;
	m_charIndex = tempCharIndex;
	m_lastChar = tempLastChar;
	m_currentLine = tempCurrentLine;
	m_currentColumn = tempCurrentColumn;

	return token;
}

void Lexer::consumeChar()
{
	if(m_charIndex == -1)
	{
		m_lastChar = QChar();
		return;
	}

	m_lastChar = m_sourceText[m_charIndex];
	m_charIndex++;
	m_currentColumn++;

	if( m_charIndex > m_sourceText.length() )
	{
		m_charIndex = -1;
		m_lastChar = QChar();
	}
}

Lexer::Token Lexer::isKeyword(const QString &value) const
{
	static int KeywordCount = sizeof(Keywords) / sizeof(KeywordPair);

	for(int i=0; i<KeywordCount; ++i)
	{
		if(value == QLatin1String(Keywords[i].keyword))
		{
			return Keywords[i].token;
		}
	}

	return Lexer::Invalid;
}
