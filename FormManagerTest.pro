#-------------------------------------------------
#
# Project created by QtCreator 2013-05-19T09:28:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FormManagerTest
TEMPLATE = app


SOURCES += main.cpp\
    mymodel.cpp \
    csvfile.cpp \
    mainTable.cpp \
    visibilityMenu.cpp \
    addDialog.cpp

HEADERS  += \
    mymodel.h \
    csvfile.h \
    mainTable.h \
    visibilityMenu.h \
    addDialog.h

RESOURCES += \
    Icons.qrc
