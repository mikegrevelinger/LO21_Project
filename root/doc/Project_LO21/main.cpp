#include "mainwindow.h"
#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#define q2c(string) string.toStdString()

int main(int countArg, char **listArg)
{
    QCoreApplication app(countArg, listArg);
    std::cout << std::flush;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("C:/uvs.db");
    if(db.open())
    {
        std::cout << "Vous êtes maintenant connecté à " << q2c(db.hostName()) << std::endl;
        //db.close();
    }
    else
    {
        std::cout << "La connexion a échouée, désolé" << std::endl;
         qDebug() << db.lastError().text();
    }
        //qDebug() << db.lastError().text();
        //qDebug() << ok;

        QSqlQuery query(db);
        query.exec("SELECT * FROM Uvs");
        while(query.next()) {
            QString Nom = query.value(0).toString();
            QString Categorie = query.value(1).toString();
            int Credits = query.value(2).toInt();
            QString Descriptif = query.value(3).toString();
            qDebug() << "Nom de l'UV: " << Nom << "Categorie:" << Categorie <<"Credits:"<< Credits<< "Descriptif: "<< Descriptif << "\n";
            //qDebug() << db.lastError();
        }


   return app.exec();
}
