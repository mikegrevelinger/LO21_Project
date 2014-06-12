#include "./class/DBManager.h"
#include "./gui/popMessage.h"
#include "./class/CursusManager.h"
#include "./class/UVManager.h"
#include "./class/ETUManager.h"
#include "./gui/rechercheInstantaneUV.h"

#include <QApplication>
#include <iostream>

#include <QPushButton>


int main(int countArg, char **listArg)
{
    QApplication app(countArg, listArg);
    DBManager & dbm = DBManager::getInstance();
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
    qDebug() << dbm.getCursusEtu(25);
    rechercheInstantaneUV ri;
    ri.show();
    return app.exec();
}
