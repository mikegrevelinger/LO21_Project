#include "./class/DBManager.h"
#include "./gui/popMessage.h"
#include <QApplication>
#include <iostream>
#include <QPushButton>

int main(int countArg, char **listArg)
{
    QApplication app(countArg, listArg);
    QPushButton button ("Hello world !");
    button.show();
    ErrorManager & e = ErrorManager::getInstance();
    DBManager & dbm = DBManager::getInstance();
    enumeration::CategorieUV c = enumeration::TM;
    dbm.rechercheUV(c);
    //dbm.ajouterUV(QString("NF02"),enumeration::TM,6,QString("Du blabla test"));
    popMessage(QString("Error"),QString("VTF"));
    e.libererInstance();
    dbm.libererInstance();
    return app.exec();
}
