#ifndef BINDINGMACROS_H
#define BINDINGMACROS_H

#define BIND_CLASS_PROCEDURE_0(className,functionName) \
	class __##className##_##functionName##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>&) \
		{ \
			classInstance->functionName(); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_BindedFunction)

#define BIND_CLASS_PROCEDURE_1(className,functionName,type1) \
	class __##className##_##functionName##_##type1##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			classInstance->functionName(p[0]->evaluate().value<type1>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_BindedFunction)

#define BIND_CLASS_PROCEDURE_2(className,functionName,type1,type2) \
	class __##className##_##functionName##_##type1##_##type2##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_BindedFunction)

#define BIND_CLASS_PROCEDURE_3(className,functionName,type1,type2,type3) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_BindedFunction)

#define BIND_CLASS_PROCEDURE_4(className,functionName,type1,type2,type3,type4) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_BindedFunction)

#define BIND_CLASS_PROCEDURE_5(className,functionName,type1,type2,type3,type4,type5) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_BindedFunction)

#define BIND_CLASS_PROCEDURE_6(className,functionName,type1,type2,type3,type4,type5,type6) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_BindedFunction)

#define BIND_CLASS_PROCEDURE_7(className,functionName,type1,type2,type3,type4,type5,type6,type7) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_BindedFunction)

#define BIND_CLASS_PROCEDURE_8(className,functionName,type1,type2,type3,type4,type5,type6,type7,type8) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_BindedFunction)

#define BIND_CLASS_PROCEDURE_9(className,functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) \
	class __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>(),p[8]->evaluate().value<type9>()); \
			return QVariant(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_BindedFunction)

#define BIND_CLASS_FUNCTION_0(className,returnType,functionName) \
	class __##className##_##returnType##_##functionName##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>&) \
		{ \
			return (returnType)classInstance->functionName(); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_BindedFunction)

#define BIND_CLASS_FUNCTION_1(className,returnType,functionName,type1) \
	class __##className##_##returnType##_##functionName##_##type1##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_BindedFunction)

#define BIND_CLASS_FUNCTION_2(className,returnType,functionName,type1,type2) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_BindedFunction)

#define BIND_CLASS_FUNCTION_3(className,returnType,functionName,type1,type2,type3) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_BindedFunction)

#define BIND_CLASS_FUNCTION_4(className,returnType,functionName,type1,type2,type3,type4) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
			return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_BindedFunction)

#define BIND_CLASS_FUNCTION_5(className,returnType,functionName,type1,type2,type3,type4,type5) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_BindedFunction)

#define BIND_CLASS_FUNCTION_6(className,returnType,functionName,type1,type2,type3,type4,type5,type6) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_BindedFunction)

#define BIND_CLASS_FUNCTION_7(className,returnType,functionName,type1,type2,type3,type4,type5,type6,type7) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_BindedFunction)

#define BIND_CLASS_FUNCTION_8(className,returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_BindedFunction)

#define BIND_CLASS_FUNCTION_9(className,returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) \
	class __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_BindedFunction : public BindedFunction<className>\
	{ \
	public: \
		QVariant execute(className* classInstance, const QList<Expression*>& p) \
		{ \
	return (returnType)classInstance->functionName(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>(),p[8]->evaluate().value<type9>()); \
		} \
	}; \
	setFunction(#functionName, new __##className##_##returnType##_##functionName##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_BindedFunction)

#define BIND_PAINTER_PROCEDURE_0(functionName) BIND_CLASS_PROCEDURE_0(QPainter,functionName)
#define BIND_PAINTER_PROCEDURE_1(functionName,type1) BIND_CLASS_PROCEDURE_1(QPainter,functionName,type1)
#define BIND_PAINTER_PROCEDURE_2(functionName,type1,type2) BIND_CLASS_PROCEDURE_2(QPainter,functionName,type1,type2)
#define BIND_PAINTER_PROCEDURE_3(functionName,type1,type2,type3) BIND_CLASS_PROCEDURE_3(QPainter,functionName,type1,type2,type3)
#define BIND_PAINTER_PROCEDURE_4(functionName,type1,type2,type3,type4) BIND_CLASS_PROCEDURE_4(QPainter,functionName,type1,type2,type3,type4)
#define BIND_PAINTER_PROCEDURE_5(functionName,type1,type2,type3,type4,type5) BIND_CLASS_PROCEDURE_5(QPainter,functionName,type1,type2,type3,type4,type5)
#define BIND_PAINTER_PROCEDURE_6(functionName,type1,type2,type3,type4,type5,type6) BIND_CLASS_PROCEDURE_6(QPainter,functionName,type1,type2,type3,type4,type5,type6)
#define BIND_PAINTER_PROCEDURE_7(functionName,type1,type2,type3,type4,type5,type6,type7) BIND_CLASS_PROCEDURE_7(QPainter,functionName,type1,type2,type3,type4,type5,type6,type7)
#define BIND_PAINTER_PROCEDURE_8(functionName,type1,type2,type3,type4,type5,type6,type7,type8) BIND_CLASS_PROCEDURE_8(QPainter,functionName,type1,type2,type3,type4,type5,type6,type7,type8)
#define BIND_PAINTER_PROCEDURE_9(functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) BIND_CLASS_PROCEDURE_9(QPainter,functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9)

#define BIND_PAINTER_FUNCTION_0(returnType,functionName) BIND_CLASS_FUNCTION_0(QPainter,returnType,functionName)
#define BIND_PAINTER_FUNCTION_1(returnType,functionName,type1) BIND_CLASS_FUNCTION_1(QPainter,returnType,functionName,type1)
#define BIND_PAINTER_FUNCTION_2(returnType,functionName,type1,type2) BIND_CLASS_FUNCTION_2(QPainter,returnType,functionName,type1,type2)
#define BIND_PAINTER_FUNCTION_3(returnType,functionName,type1,type2,type3) BIND_CLASS_FUNCTION_3(QPainter,returnType,functionName,type1,type2,type3)
#define BIND_PAINTER_FUNCTION_4(returnType,functionName,type1,type2,type3,type4) BIND_CLASS_FUNCTION_4(QPainter,returnType,functionName,type1,type2,type3,type4)
#define BIND_PAINTER_FUNCTION_5(returnType,functionName,type1,type2,type3,type4,type5) BIND_CLASS_FUNCTION_5(QPainter,returnType,functionName,type1,type2,type3,type4,type5)
#define BIND_PAINTER_FUNCTION_6(returnType,functionName,type1,type2,type3,type4,type5,type6) BIND_CLASS_FUNCTION_6(QPainter,returnType,functionName,type1,type2,type3,type4,type5,type6)
#define BIND_PAINTER_FUNCTION_7(returnType,functionName,type1,type2,type3,type4,type5,type6,type7) BIND_CLASS_FUNCTION_7(QPainter,returnType,functionName,type1,type2,type3,type4,type5,type6,type7)
#define BIND_PAINTER_FUNCTION_8(returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8) BIND_CLASS_FUNCTION_8(QPainter,returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8)
#define BIND_PAINTER_FUNCTION_9(returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9) BIND_CLASS_FUNCTION_9(QPainter,returnType,functionName,type1,type2,type3,type4,type5,type6,type7,type8,type9)

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

#define BEGIN_BIND_CLASS(className) \
	class __##className##_Prototype : public ClassPrototype<className> \
	{ \
	public: \
		__##className##_Prototype() { \

#define END_BIND_CLASS(className) \
		} \
	}; \
	addClassPrototype(#className, new __##className##_Prototype);

#define BIND_CLASS_CONSTRUCTOR_0(className) \
	class __##className##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
			scope->m_classInstance = new className(); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_1(className,type1) \
	class __##className##_##type1##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
			scope->m_classInstance = new className(p[0]->evaluate().value<type1>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_2(className,type1,type2) \
	class __##className##_##type1##_##type2##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_3(className,type1,type2,type3) \
	class __##className##_##type1##_##type2##_##type3##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_4(className,type1,type2,type3,type4) \
	class __##className##_##type1##_##type2##_##type3##_##type4##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_##type4##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_5(className,type1,type2,type3,type4,type5) \
	class __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_6(className,type1,type2,type3,type4,type5,type6) \
	class __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_7(className,type1,type2,type3,type4,type5,type6,type7) \
	class __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_8(className,type1,type2,type3,type4,type5,type6,type7,type8) \
	class __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_Constructor)

#define BIND_CLASS_CONSTRUCTOR_9(className,type1,type2,type3,type4,type5,type6,type7,type8,type9) \
	class __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_Constructor : public ClassConstructor \
	{ \
		Scope* create(Scope *context, const QList<Expression*> &p) \
		{ \
			ClassScope<className>* scope = new ClassScope<className>((ClassPrototype<className>*)context->classPrototype(#className)); \
	scope->m_classInstance = new className(p[0]->evaluate().value<type1>(),p[1]->evaluate().value<type2>(),p[2]->evaluate().value<type3>(),p[3]->evaluate().value<type4>(),p[4]->evaluate().value<type5>(),p[5]->evaluate().value<type6>(),p[6]->evaluate().value<type7>(),p[7]->evaluate().value<type8>(),p[8]->evaluate().value<type9>()); \
			return scope; \
		} \
	}; \
	addClassConstructor(#className, new __##className##_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8##_##type9##_Constructor)

#endif
