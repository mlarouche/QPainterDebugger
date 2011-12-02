#ifndef PAINTERCONTEXT_H
#define PAINTERCONTEXT_H

#include <QtCore/QHash>
#include <QtCore/QVariant>

class QPainter;
class PainterCommand;

class PainterContext
{
public:
	PainterContext();

	QPainter *painter() const
	{
		return m_painter;
	}

	void setPainter(QPainter* painter)
	{
		m_painter = painter;
	}

	QVariant variable(const QString &identifier);
	void setVariable(const QString &identifier, const QVariant &value);

	bool isValidFunction(const QString &functionName) const;
	PainterCommand* function(const QString &functionName) const;
	void setFunction(const QString &functionName, PainterCommand* function);

private:
	QPainter* m_painter;
	QHash<QString,QVariant> m_variables;
	QHash<QString,PainterCommand*> m_functions;
};

#endif
