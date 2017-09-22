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
        src/window/login.cpp \
        src/net/client.cpp \
        src/window/friends.cpp \
        src/window/talk.cpp \
        src/config/config.cpp \
        src/manager.cpp \
        src/window/window.cpp \
        src/window/content.cpp \
        src/ui/haloBorder.cpp \
        src/ui/haloWidget.cpp \
        src/ui/ppDialog.cpp \
        src/ui/ppLabel.cpp \
        src/ui/ppMenu.cpp \
        src/ui/ppButton.cpp \
        main.cpp 
		
HEADERS += \
        src/net/client.h \
        src/window/login.h \
        src/window/friends.h \
        src/window/talk.h \
        src/config/config.h \
        src/config/icon.h \
        src/base/queue.h \
        src/base/spinlock.h \
        src/base/model.h \
        src/window/window.h \
        src/window/content.h \
        src/ui/haloBorder.h \
        src/ui/haloWidget.h \
        src/ui/ppDialog.h \
        src/ui/ppLabel.h \
        src/ui/ppMenu.h \
        src/ui/ppButton.h \
        src/manager.h 

