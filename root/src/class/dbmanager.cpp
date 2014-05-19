#include "dbmanager.h"

DBManager::DBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    /** Pour connaitre le chemin du repertoir courant de façon automatique */
    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","");
    // /src/database/uvs.db
    qDebug() << CurrentDir;
    db.setDatabaseName(CurrentDir);
    if (!db.open()){
        throw ErrorDB(QString("Erreur ouverture de la base de donnee "));
        db.close();
    }
}

DBManager::~DBManager(){
    db.close();
}

/* Debut partie SINGLETON */
HandlerSingleton<DBManager> DBManager::handler = HandlerSingleton<DBManager> ();

DBManager & DBManager::getInstance(){
    if (!handler.instance)
        handler.instance = new DBManager;
    return *handler.instance;
}

void DBManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance = 0;
    }
}
/* Fin partie SINGLETON */



