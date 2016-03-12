#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T12:18:41
#
#-------------------------------------------------

QT       += core gui
RC_FILE  += myico.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Menu_and_Toolbar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    window_1.cpp \
    window_2.cpp \
    window_3.cpp \
    window_car.cpp \
    window_4.cpp \
    window_5.cpp \
    window_6.cpp

HEADERS  += mainwindow.h \
    window_1.h \
    window_2.h \
    window_3.h \
    window_car.h \
    window_4.h \
    window_5.h \
    window_6.h

FORMS    += mainwindow.ui

RESOURCES += \
    rsc.qrc

DISTFILES += \
    myico.rc
