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
    DrawTextCommand.cpp \
    Expression.cpp \
    Lexer.cpp \
    Parser.cpp \
    ASTNode.cpp \
    IdentifierExpression.cpp \
    FunctionCall.cpp \
    RootNode.cpp \
    VariableAssignment.cpp

HEADERS  += QPainterDebuggerMainWindow.h \
    PainterContext.h \
    PainterCommand.h \
    DrawTextCommand.h \
    Expression.h \
    Lexer.h \
    Parser.h \
    ASTNode.h \
    IdentifierExpression.h \
    FunctionCall.h \
    RootNode.h \
    VariableAssignment.h

FORMS    += QPainterDebuggerMainWindow.ui


























