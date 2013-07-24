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
    visibilityMenu.cpp \
    addDialog.cpp \
    EntryFields/NumberField.cpp \
    CsvReader.cpp \
    EntryFields/StringField.cpp \
    EntryFields/BoolField.cpp \
    EntryFields/AbstractEntry.cpp \
    CsvLoc.cpp \
    MainTableModel.cpp \
    MainTable.cpp \
    BundleReader.cpp \
    FileSelector.cpp \
    MainWindow.cpp

HEADERS  += \
    visibilityMenu.h \
    addDialog.h \
    EntryFields/NumberField.h \
    CsvReader.h \
    EntryFields/StringField.h \
    EntryFields/BoolField.h \
    EntryFields/AbstractEntry.h \
    CsvLoc.h \
    MainTableModel.h \
    MainTable.h \
    BundleReader.h \
    FileSelector.h \
    MainWindow.h

RESOURCES += \
    Icons.qrc
