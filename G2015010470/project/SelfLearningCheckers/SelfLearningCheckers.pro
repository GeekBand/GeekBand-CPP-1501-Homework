#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T07:45:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SelfLearningCheckers
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    checkersdata.cpp \
    chessboard.cpp \
    colleague.cpp \
    mediator.cpp \
    event.cpp \
    checkersstate.cpp \
    player.cpp \
    movesrandom.cpp

HEADERS  += window.h \
    checkersdata.h \
    chessboard.h \
    mediator.h \
    event.h \
    colleague.h \
    checkersstate.h \
    enum.h \
    movestrategy.h \
    player.h

FORMS    +=
