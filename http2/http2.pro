QT += core
QT -= gui
QT += network

TARGET = http2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    html.cpp

HEADERS += \
    html.h

