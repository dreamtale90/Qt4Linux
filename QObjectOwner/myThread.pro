TEMPLATE = app

QT += core

CONFIG += console

TARGET = myThread

SOURCES += main.cpp \
    myThread.cpp

HEADERS += myThread.h

LIBS += -lpthread
