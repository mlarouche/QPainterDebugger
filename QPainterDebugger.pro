#-------------------------------------------------
#
# Project created by QtCreator 2011-11-24T21:01:26
#
#-------------------------------------------------

QT       += core gui

TARGET = QPainterDebugger
TEMPLATE = app


SOURCES += main.cpp\
        QPainterDebuggerMainWindow.cpp \
    PainterContext.cpp \
    PainterCommand.cpp \
    Lexer.cpp \
    Parser.cpp \
    ASTNode.cpp \
    IdentifierExpression.cpp \
    FunctionCall.cpp \
    RootNode.cpp \
    VariableAssignment.cpp \
    LiteralExpression.cpp \
    Expression.cpp \
    BinaryExpression.cpp \
    UnaryExpression.cpp \
    NameMangling.cpp \
    DSLHighlighter.cpp \
    Scope.cpp

HEADERS  += QPainterDebuggerMainWindow.h \
    PainterContext.h \
    PainterCommand.h \
    Lexer.h \
    Parser.h \
    ASTNode.h \
    IdentifierExpression.h \
    FunctionCall.h \
    RootNode.h \
    VariableAssignment.h \
    LiteralExpression.h \
    Expression.h \
    BinaryExpression.h \
    UnaryExpression.h \
    NameMangling.h \
    DSLHighlighter.h \
    Scope.h

FORMS    += QPainterDebuggerMainWindow.ui












































