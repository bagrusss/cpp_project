#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T19:25:05
#
#-------------------------------------------------

QT       += core network gui
QT += dbus


TARGET = daemon0
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    daemon.cpp \
    ../congratulations0/dbusconnector.cpp

HEADERS += \
    daemon.h \
    ../congratulations0/dbusconnector.h

QDBUS_DEBUG = 1

QMAKE_CFLAGS_DEBUG += -std=c++11 -fpermissive
QMAKE_LFLAGS += -std=c++11 -fpermissive
QMAKE_CXXFLAGS += -std=c++11 -fpermissive





unix:!macx: LIBS += -L$$PWD/../congratulations/lib/ -lcongratulations_lib

INCLUDEPATH += $$PWD/../congratulations/lib/include
DEPENDPATH += $$PWD/../congratulations/lib/include

unix:!macx: LIBS += -L$$PWD/../congratulations/yaml/ -lyaml-cpp

INCLUDEPATH += $$PWD/../congratulations/yaml
DEPENDPATH += $$PWD/../congratulations/yaml

unix:!macx: PRE_TARGETDEPS += $$PWD/../congratulations/yaml/libyaml-cpp.a
