#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T10:59:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += /MP

SOURCES += \
        main.cpp \
        src/login.cpp \
        src/client.cpp \
        src/friends.cpp \
        src/talk.cpp \
        src/config.cpp \
        src/manager.cpp \
        src/window.cpp \
        src/content.cpp \
        src/queue.cpp 
		
HEADERS += \
        src/login.h \
        src/client.h \
        src/friends.h \
        src/talk.h \
        src/config.h \
        src/manager.h \
        src/window.h \
        src/content.h \
        src/queue.h \
        src/spinlock.h \
        src/model.h 
