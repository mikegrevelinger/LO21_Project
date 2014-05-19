QT += sql
QT += widgets
QT += gui
SOURCES += main.cpp \
    enumeration/enumeration.cpp \
    class/uvmanager.cpp \
    class/dbmanager.cpp \
    class/ErrorDB.cpp

HEADERS += \
    enumeration/enumeration.h \
    class/uvmanager.h \
    enumeration/enumiterator.h \
    class/ErrorDB.h \
    class/dbmanager.h \
    class/HandlerSingleton.h
