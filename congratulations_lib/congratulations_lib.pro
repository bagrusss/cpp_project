#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T19:58:06
#
#-------------------------------------------------

QT       += network sql gui


TARGET = congratulations_lib
TEMPLATE = lib

DEFINES += CONGRATULATIONS_LIB_LIBRARY

SOURCES += \
    network.cpp \
    dbmanager.cpp \
    listelement.cpp \
    sqlite/sqlite3.c \
    dbmanagerhelpers.cpp \
    templatesdbmanager.cpp \
    friendsdbmanager.cpp \
    bdaysdbmanager.cpp \
    json.cpp

HEADERS +=\
        congratulations_lib_global.h \
    network.h \
    dbmanager.h \
    listelement.h \
    settingsheader.h \
    clearmemoryhelpers.h \
    sqlite/sqlite3ext.h \
    sqlite/sqlite3.h \
    json.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

QMAKE_CFLAGS_DEBUG += -std=c++11 -fPIC
QMAKE_LFLAGS += -std=c++11 -fPIC
QMAKE_CXXFLAGS += -std=c++11 -fPIC

