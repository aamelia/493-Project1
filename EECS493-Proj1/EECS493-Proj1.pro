#-------------------------------------------------
#
# Project created by QtCreator 2013-02-17T15:28:39
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EECS493-Proj1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../flickrcollector.cpp \
    ../imagecollector.cpp

HEADERS  += mainwindow.h \
    ../flickrcollector.h \
    ../imagecollector.h

FORMS    += mainwindow.ui
