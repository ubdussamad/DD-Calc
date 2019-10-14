TEMPLATE = app
TARGET = lex

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += main.cpp window.cpp suite.cpp
HEADERS += window.h