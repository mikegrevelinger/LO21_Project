QT += sql
QT += widgets
QT += gui
SOURCES += main.cpp \
    enumeration/enumeration.cpp \
    class/DBManager.cpp \
    class/UVManager.cpp \
    gui/popMessage.cpp \
    class/ErrorManager.cpp \
    class/ETUManager.cpp

HEADERS += \
    enumeration/enumeration.h \
    enumeration/enumiterator.h \
    class/HandlerSingleton.h \
    class/DBManager.h \
    class/UVManager.h \
    gui/popMessage.h \
    class/ErrorManager.h \
    class/ETUManager.h
