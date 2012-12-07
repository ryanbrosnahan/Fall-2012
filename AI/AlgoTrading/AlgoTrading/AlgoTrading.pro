#-------------------------------------------------
#
# Project created by QtCreator 2012-11-29T01:07:58
#
#-------------------------------------------------

QT       += core gui

TARGET = AlgoTrading
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    algo/movingaverage.cpp \
    data/datafeed.cpp \
    data/iqfeed.cpp \
    data/emulatedfeed.cpp \
    algo/seasonal.cpp

HEADERS  += mainwindow.h \
    algo/movingaverage.h \
    data/datafeed.h \
    data/iqfeed.h \
    data/emulatedfeed.h \
    algo/seasonal.h

FORMS    += mainwindow.ui
