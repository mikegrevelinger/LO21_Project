#include "./class/Cursus.h"
#include "./class/CursusFactory.h"
#include "./class/CursusManager.h"
#include "./class/DBManager.h"
#include "./class/DossierManager.h"
#include "./class/ErrorManager.h"
#include "./class/ETUManager.h"
#include "./class/HandlerSingleton.h"
#include "./class/Prevision.h"
#include "./class/UVManager.h"
#include "./class/VisitorCursus.h"
#include "./gui/popMessage.h"

#include "./enumeration/enumeration.h"

#include "./gui/MainWindow.h"
#include "./gui/popMessage.h"

#include <QApplication>


/*! \mainpage LO21 - UT'Profiler
 *
 * \section intro_sec Introduction
 *
 * Ce logiciel à été modélisé et réaliser par GREVELINGER Mike et NOGARET Baptiste dans le cadre de l'UV LO21 : Programmation et conception orientees objet.
 * Ce projet a été codé en C++, l'interface graphique utilisant Qt.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */


int main(int countArg, char **listArg)
{
    QApplication app(countArg, listArg);
    //DBManager & dbm = DBManager::getInstance();
    CursusFactory c;
    Cursus * q = c.makeCursus(1);
    qDebug() <<QString::number(q->remplireCursus("TC"));
    VisitorNbCreditCS nbCS;
    qDebug() <<QString::number(q->accept(nbCS));
    VisitorNbCreditTM nbTM;
    qDebug() <<QString::number(q->accept(nbTM));
    VisitorNbCreditTSH nbTSH;
    qDebug() <<QString::number(q->accept(nbTSH));
    VisitorNbCreditLibre nbLibre;
    qDebug() <<QString::number(q->accept(nbLibre));
    VisitorNbCreditPCB nbPCB;
    qDebug() <<QString::number(q->accept(nbPCB));
    VisitorNbCreditFiliere nbPSF;
    qDebug() <<QString::number(q->accept(nbPSF));

    MainWindow * m = new MainWindow;
    //QDate d(1993,12,23);
    //qDebug() <<dbm.ajouteUV("NF92",enumeration::CS,6,"ENcore plus de paroles");
    //qDebug() <<dbm.ajouteUV("LO21",enumeration::TM,6,"La perfection.");
    //dbm.rechercheUV("NF92");
    //dbm.ajouteETU("Grevelinger","Mike",enumeration::Madame,"Francais",d,enumeration::Printemps,2014);
    //qDebug() <<dbm.getIdETU("Nogaret");
    /*
    bool ajouteETU(QString const nom, QString const prenom, enumeration::Civilite civ,
                   QString const nationalite, QDate const dateDeNaissance, enumeration::Saison s, const int annee,
                   const int creditsEqui = 0, QString const cursus = NULL, const int numeroSemestre = 0,  const int creditsTOTAL = 0, const int creditsCS = 0,
                   const int creditsTM = 0, const int creditsTSH = 0, const int nbCreditEtranger = 0);
    */
    m->show();
    return app.exec();
}
