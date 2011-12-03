#ifndef IDENTIFIEREXPRESSION_H
#define IDENTIFIEREXPRESSION_H

#include "Expression.h"

class IdentifierExpression : public Expression
{
public:
	IdentifierExpression(const QString &identifier, PainterContext* context);
	virtual ~IdentifierExpression();

	virtual QVariant::Type type() const;

	virtual QVariant evaluate();

private:
	QString m_identifier;
};

#endif
