#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T15:02:23
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BroadcastServer
TEMPLATE = app


SOURCES += main.cpp\
        serverwidget.cpp

HEADERS  += serverwidget.h

FORMS    +=


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BroadcastLib/release/ -lBroadcastLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BroadcastLib/debug/ -lBroadcastLib
else:unix: LIBS += -L$$OUT_PWD/../BroadcastLib/ -lBroadcastLib

INCLUDEPATH += $$PWD/../BroadcastLib
DEPENDPATH += $$PWD/../BroadcastLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../BroadcastLib/release/libBroadcastLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../BroadcastLib/debug/libBroadcastLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../BroadcastLib/release/BroadcastLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../BroadcastLib/debug/BroadcastLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../BroadcastLib/libBroadcastLib.a
