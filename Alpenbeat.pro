#-------------------------------------------------
#
# Project created by QtCreator 2012-04-06T13:39:26
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Alpenbeat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    universe.cpp \
    receiver.cpp \
    animator.cpp \
    dialoganimator.cpp \
    olareceiver.cpp \
    olaoutthread.cpp \
    effectanimator.cpp \
    beateffectanimator.cpp \
    alpenbeatglreceiver.cpp

HEADERS  += mainwindow.h \
    universe.h \
    receiver.h \
    animator.h \
    dialoganimator.h \
    olareceiver.h \
    olaoutthread.h \
    effectanimator.h \
    beateffectanimator.h \
    libbeat/subband.h \
    libbeat/soundrecorder.h \
    libbeat/soundbuffer.h \
    libbeat/pulserecorder.h \
    libbeat/fft.h \
    libbeat/beatcontroller.h \
    libbeat/beatanalyser.h \
    libbeat/alsarecorder.h \
    alpenbeatglreceiver.h

FORMS    += mainwindow.ui \
    dialoganimator.ui \
    effectanimator.ui \
    beateffectanimator.ui

LIBS += -lolaserver -lola -lolacommon -lprotobuf -lbeat -lGLU
