#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T22:05:03
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    network.cpp

HEADERS  += mainwindow.h \
    network.h

FORMS    += mainwindow.ui

QMAKE_CFLAGS_DEBUG += -std=c++11 -fpermissive
QMAKE_LFLAGS += -std=c++11 -fpermissive
QMAKE_CXXFLAGS += -std=c++11 -fpermissive
