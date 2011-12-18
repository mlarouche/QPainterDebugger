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
		QString typeName;
		switch(type)
		{
			case QVariant::Bool:
				typeName = QLatin1String("|bool");
				break;
			case QVariant::Int:
				typeName = QLatin1String("|int");
				break;
			case QVariant::Double:
				typeName = QLatin1String("|qreal");
				break;
			case QVariant::String:
				typeName = QLatin1String("|QString");
				break;
		}

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
