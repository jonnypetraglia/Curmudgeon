#-------------------------------------------------
#
# Project created by QtCreator 2013-05-27T16:51:38
#
#-------------------------------------------------

VERSION = 1.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Curmudgeon
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    SoundButton.cpp \
    SoundBoard.cpp \
    VersionDialog.cpp \
    CIniFile/IniFile.cpp \
    Options.cpp

HEADERS  += MainWindow.h \
    SoundButton.h \
    Options.h \
    SoundBoard.h \
    AudioPlayerClass/AudioPlayerCallback.h \
    VersionDialog.h \
    AudioPlayerClass/AudioPlayer.h \
    AudioPlayerClass/AudioPlayerFactory.h \
    CIniFile/IniFile.h \
    qlabelwrapellip.h \
    QSliderFixedSize.h

FORMS    += mainwindow.ui

RESOURCES += resources.qrc

macx {
    ICON = images/logo.icns
    SOURCES += AudioPlayerClass/AudioPlayerOsx.cpp
    HEADERS += AudioPlayerClass/AudioPlayerOsx.h
    LIBS += -framework CoreFoundation
    LIBS += -framework AudioToolbox
    CONFIG += static
    LIBS += -dead_strip
}
win32 {
    ICON = images/logo.ico
    SOURCES += AudioPlayerClass/AudioPlayerWin.cpp
    HEADERS += AudioPlayerClass/AudioPlayerWin.h
    LIBS += -lwinmm \
            -lrpcrt4
    RC_FILE = winicon.rc
}
unix:!macx {
    # On Linux this includes the -dev package of gstreamer.
    # On Ubuntu-like systems the package is:    libgstreamer0.10-dev, libgstreamer-plugins-base0.10-dev

    CONFIG += link_pkgconfig
    PKGCONFIG += gstreamer-0.10 \
                 gstreamer-base-0.10 \
                 #gstreamer-interfaces-0.10 \
                 gstreamer-audio-0.10
    SOURCES += AudioPlayerClass/AudioPlayerGnu.cpp
    HEADERS += AudioPlayerClass/AudioPlayerGnu.h


    #Install
    #PREFIX = /opt
    #BINDIR = $$PREFIX/curmudgeon
    #DATADIR = $$BINDIR

    #DEFINES += DATADIR=\\\"$$DATADIR\\\" PKGDATADIR=\\\""$$PKGDATADIR\\\"
    #INSTALLS += target desktop icon26 icon48 icon64
}

#QMAKE_CXX = g++  #used for testing g++/Ming on Mac



#mpg123
#LIBS += /usr/local/lib/libmpg123.dylib

#ffmpeg
#INCLUDEPATH += include
#LIBS += -Llib
#LIBS += -lavcodec
#LIBS += -lavfilter
#LIBS += -lavformat
#LIBS += -lavutil
#LIBS += -lswscale

#ao
#INCLUDEPATH += libao/include


#SFML
#LIBS += -framework sfml-audio
#LIBS += -framework sfml-system

OTHER_FILES += \
    IconNotes.txt


