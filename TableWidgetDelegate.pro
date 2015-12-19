#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T10:31:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TableWidgetDelegate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inputdelegate.cpp \
    buttondelegate.cpp

HEADERS  += mainwindow.h \
    inputdelegate.h \
    buttondelegate.h

FORMS    += mainwindow.ui
