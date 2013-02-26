#-------------------------------------------------
#
# Project created by QtCreator 2013-02-19T17:18:18
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project1
TEMPLATE = app
CONFIG -= x86_64

SOURCES += main.cpp\
        mainwindow.cpp \
    flickrcollector.cpp \
    imagecollector.cpp \
    previewarea.cpp

HEADERS  += mainwindow.h \
    flickrcollector.h \
    imagecollector.h \
    previewarea.h
