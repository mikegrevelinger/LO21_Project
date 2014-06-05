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
    ErrorManager & e = ErrorManager::getInstance();
    DBManager & dbm = DBManager::getInstance();
    UVManager & uvm = UVManager::getInstance();
    QDate d(1993,6,30);
    qDebug() <<dbm.ajouteUV("NF92",enumeration::CS,6,"Blabla");
    dbm.rechercheUV("NF92");
    //dbm.ajouteETU("Nogaret","Baptiste",enumeration::Monsieur,"Francais",d);
    //dbm.rechercheETU("Noga");
    rechercheInstantaneUV ri;
    ri.show();
    return app.exec();
}
