QT += core
QT -= gui
QT+=xml

TARGET = QSetting
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qxmlsax.cpp

HEADERS += \
    qxmlsax.h

