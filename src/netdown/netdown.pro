#-------------------------------------------------
#
# Project created by QtCreator 2015-12-17T20:43:15
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = netdown
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += static

TEMPLATE = app

QMAKE_INCDIR += ../launchopenvpn/

SOURCES += main.cpp \
    ../launchopenvpn/common.cpp \
    runit.cpp

HEADERS  += \
    ../launchopenvpn/common.h \
    runit.h
