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
	~PainterContext();

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
	void bindFunctions();

private:
	QPainter* m_painter;
	QHash<QString,QVariant> m_variables;
	QHash<QString,PainterCommand*> m_functions;
};

#define BIND_PAINTER_FUNCTION_0(functionName) \
	class __##functionName##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>&) \
		{ \
			painter->functionName(); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_PainterCommand)

#define BIND_PAINTER_FUNCTION_1(functionName,type1) \
	class __##functionName##_##type1##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_PainterCommand)

#define BIND_PAINTER_FUNCTION_2(functionName,type1,type2) \
	class __##functionName##_##type1##_##type2##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_PainterCommand)

#define BIND_PAINTER_FUNCTION_3(functionName,type1,type2,type3) \
	class __##functionName##_##type1##_##type2##_##type3##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_PainterCommand)

#define BIND_PAINTER_FUNCTION_4(functionName,type1,type2,type3,type4) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
			painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_PainterCommand)

#define BIND_PAINTER_FUNCTION_5(functionName,type1,type2,type3,type4,type5) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_PainterCommand)

#define BIND_PAINTER_FUNCTION_6(functionName,type1,type2,type3,type4,type5,type6) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_PainterCommand)

#define BIND_PAINTER_FUNCTION_7(functionName,type1,type2,type3,type4,type5,type6,type7) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_PainterCommand)

#define BIND_PAINTER_FUNCTION_8(functionName,type1,type2,type3,type4,type5,type6,type7,type8) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_PainterCommand)

#define BIND_PAINTER_FUNCTION_9(functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) \
	class __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_PainterCommand : public PainterCommand \
	{ \
	public: \
		void execute(QPainter* painter, const QList<Expression*>& p) \
		{ \
	painter->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>(),p[8]->evaluate().value<type9>()); \
		} \
	}; \
	setFunction(#functionName, new __##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_PainterCommand)

#endif
