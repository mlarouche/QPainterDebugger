#ifndef PAINTERCONTEXT_H
#define PAINTERCONTEXT_H

#include "Scope.h"

class QPainter;
class PainterCommand;

class PainterContext : public Scope
{
public:
	PainterContext();
	~PainterContext();

	QPainter *painter() const
	{
		return m_painter;
	}

	void setPainter(QPainter* painter)
	{
		m_painter = painter;
	}

	bool isValidFunction(const QString &functionName) const;
	PainterCommand* function(const QString &functionName) const;
	void setFunction(const QString &functionName, PainterCommand* function);

private:
	void bindEnums();
	void bindFunctions();

private:
	QPainter* m_painter;
	QHash<QString,PainterCommand*> m_functions;
};

#define BIND_PAINTER_PROCEDURE_0(functionName) \
	class __##functionName##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>&) \
		{ \
			painter->functionName(); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_1(functionName,type1) \
	class __##functionName##_##type1##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_2(functionName,type1,type2) \
	class __##functionName##_##type1##_##type2##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_3(functionName,type1,type2,type3) \
	class __##functionName##_##type1##_##type2##_##type3##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_4(functionName,type1,type2,type3,type4) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_5(functionName,type1,type2,type3,type4,type5) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_6(functionName,type1,type2,type3,type4,type5,type6) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_7(functionName,type1,type2,type3,type4,type5,type6,type7) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_8(functionName,type1,type2,type3,type4,type5,type6,type7,type8) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_PainterCommand)

#define BIND_PAINTER_PROCEDURE_9(functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>(),p[8]->evaluate().value<type9>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_PainterCommand)

#define BIND_PAINTER_FUNCTION_0(returnType,functionName) \
	class __##returnType##_##functionName##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>&) \
		{ \
			return (returnType)painter->functionName(); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_PainterCommand)

#define BIND_PAINTER_FUNCTION_1(returnType,functionName,type1) \
	class __##returnType##_##functionName##_##type1##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			return painter->functionName(p[0]->evaluate().value<type1>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_PainterCommand)

#define BIND_PAINTER_FUNCTION_2(returnType,functionName,type1,type2) \
	class __##returnType##_##functionName##_##type1##_##type2##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_PainterCommand)

#define BIND_PAINTER_FUNCTION_3(returnType,functionName,type1,type2,type3) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_PainterCommand)

#define BIND_PAINTER_FUNCTION_4(returnType,functionName,type1,type2,type3,type4) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_PainterCommand)

#define BIND_PAINTER_FUNCTION_5(returnType,functionName,type1,type2,type3,type4,type5) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_PainterCommand)

#define BIND_PAINTER_FUNCTION_6(returnType,functionName,type1,type2,type3,type4,type5,type6) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_PainterCommand)

#define BIND_PAINTER_FUNCTION_7(returnType,functionName,type1,type2,type3,type4,type5,type6,type7) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_PainterCommand)

#define BIND_PAINTER_FUNCTION_8(returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_PainterCommand)

#define BIND_PAINTER_FUNCTION_9(returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) \
	class __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_PainterCommand : public PainterCommand \
	{ \
	public: \
		QVariant execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	return painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>(),p[8]->evaluate().value<type9>()); \
		} \
	}; \
	setFunction(#functionName, new __##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_PainterCommand)

#define BEGIN_BIND_ENUM(enumName) \
	class __Enum_##enumName##__ : public Scope \
	{ \
	public: \
		__Enum_##enumName##__() { \

#define END_BIND_ENUM(enumName) \
		} \
	}; \
	addScope(#enumName, new __Enum_##enumName##__); \

#define ENUM_NAME_VALUE(friendlyName, value) setVariable(#friendlyName,value)

#endif
