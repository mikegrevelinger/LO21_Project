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
    gui/dialogAjouterDossier.cpp \
    class/Prevision.cpp \
    gui/rechercheInstantaneDossiercpp.cpp \
    gui/dialogModifieUV.cpp \
    gui/rechercheInstantaneCursus.cpp \
    gui/dialogAjouterCursusTC.cpp \
    gui/dialogAjouterCursus.cpp \
    gui/dialogAjouterCursusBranche.cpp \
    gui/dialogAjouterFiliere.cpp \
    gui/dialogAjouterMineur.cpp \
    gui/dialogAjouterUVTC.cpp

HEADERS += \
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
    gui/dialogAjouterDossier.h \
    class/Prevision.h \
    gui/rechercheInstantaneDossier.h \
    enumeration/enumeration.h \
    gui/dialogModifieUV.h \
    gui/rechercheInstantaneCursus.h \
    gui/dialogAjouterCursusTC.h \
    gui/dialogAjouterCursus.h \
    gui/dialogAjouterCursusBranche.h \
    gui/dialogAjouterFiliere.h \
    gui/dialogAjouterMineur.h \
    gui/dialogAjouterUVTC.h

FORMS += \
    gui/mainwindow.ui \
    gui/dialogAjouterUV.ui \
    gui/dialogAjouterDossier.ui \
    gui/dialogModifieUV.ui \
    gui/dialogAjouterCursusTC.ui \
    gui/dialogAjouterCursus.ui \
    gui/dialogAjouterCursusBranche.ui \
    gui/dialogAjouterFiliere.ui \
    gui/dialogAjouterMineur.ui \
    gui/dialogAjouterUVTC.ui
