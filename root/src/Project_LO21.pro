QT += sql
QT += widgets
QT += gui

SOURCES += main.cpp \
    enumeration/enumeration.cpp \
    class/DBManager.cpp \
    class/UVManager.cpp \
    gui/popMessage.cpp \
    class/ErrorManager.cpp \
    class/ETUManager.cpp \
    class/CursusManager.cpp \
    gui/rechercheInstantaneUV.cpp \
    class/DossierManager.cpp \
    class/Cursus.cpp \
    class/CursusFactory.cpp \ 
    class/VisitorCursus.cpp \
    gui/MainWindow.cpp \
    gui/menuIcon.cpp \
    gui/ClickableQLabel.cpp \
    gui/dialogAjouterUV.cpp \
    gui/dialogAjouterCursus.cpp \
    gui/dialogAjouterDossier.cpp \
    class/Prevision.cpp \
    gui/rechercheInstantaneDossiercpp.cpp

HEADERS += \
    enumeration/enumeration.h \
    enumeration/enumiterator.h \
    class/HandlerSingleton.h \
    class/DBManager.h \
    class/UVManager.h \
    gui/popMessage.h \
    class/ErrorManager.h \
    class/ETUManager.h \
    class/CursusManager.h \
    gui/rechercheInstantaneUV.h \
    class/DossierManager.h \
    class/Cursus.h \
    class/CursusFactory.h \
    class/VisitorCursus.h \
    gui/MainWindow.h \
    gui/menuIcon.h \
    gui/ClickableQLabel.h \
    gui/dialogAjouterUV.h \
    gui/dialogAjouterCursus.h \
    gui/dialogAjouterDossier.h \
    class/Prevision.h \
    gui/rechercheInstantaneDossier.h

FORMS += \
    gui/mainwindow.ui \
    gui/dialogAjouterUV.ui \
    gui/dialogAjouterCursus.ui \
    gui/dialogAjouterDossier.ui
