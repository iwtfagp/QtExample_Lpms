#-------------------------------------------------
#
# Project created by QtCreator 2015-02-03T16:50:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lpms_QT_example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(D:\LIB\Qwt-6.1.2\include)

Release : LIBS +=   $$quote(D:\LIB\Qwt-6.1.2\lib\qwt.lib)\
                    $$quote(D:\LIB\OpenMAT-1.3.4\lib\x86\LpSensor.lib)

Debug : LIBS +=   $$quote(D:\LIB\OpenMAT-1.3.4\lib\x86\LpSensorD.lib)
