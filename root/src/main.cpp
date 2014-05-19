#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#include <QString>

#define q2c(string) string.toStdString()

int main(int countArg, char **listArg)
{
    QCoreApplication app(countArg, listArg);
    std::cout << std::flush;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    /** Pour connaitre le chemin du repertoir courant */
    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","src/database/uvs.db");
    qDebug() << CurrentDir;
    db.setDatabaseName(CurrentDir);
    if(db.open())
    {
        std::cout << "Vous etes maintenant connecte a " << q2c(db.hostName()) << std::endl;
        //db.close();
    }
    else
    {
        std::cout << "La connexion a échouée, désolé" << std::endl;
         qDebug() << db.lastError().text();
    }
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
