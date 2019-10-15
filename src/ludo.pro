TEMPLATE = app
TARGET = lex

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

SOURCES += main.cpp window.cpp suite.cpp
HEADERS += window.h