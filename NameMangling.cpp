#include "NameMangling.h"

// Qt includes
#include <QtCore/QVariant>

// Local includes
#include "Expression.h"

NameMangling::NameMangling()
{
}

QString NameMangling::mangleFunctionName(const QString &functionName, const QList<int> &parametersTypes)
{
	QString result("?");
	result += functionName;

	foreach(int type, parametersTypes)
	{
		QString typeName(QMetaType::typeName(type));

		result += '|';
		result += typeName;
	}

	return result;
}

QString NameMangling::mangleFunctionName(const QString &functionName, const QList<Expression*> &expressionList)
{
	QList<int> types;

	foreach(Expression* expression, expressionList)
	{
		types.append(static_cast<int>(expression->type()));
	}

	return mangleFunctionName(functionName, types);
}
