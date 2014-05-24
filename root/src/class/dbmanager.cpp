#include "DBmanager.h"

DBManager::DBManager() {
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    /** Pour connaitre le chemin du repertoir courant de façon automatique */
    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","src/database/uvs.db");
    qDebug() << CurrentDir;
    db.setDatabaseName(CurrentDir);
    if (db.isValid())
    {
        db.open();
        if (db.isOpen())
        {
            QSqlQuery searchQuery(db);
            searchQuery.prepare("SELECT * FROM myTable");
            searchQuery.exec();
            if(searchQuery.isActive())
            {
                /*
                model->setQuery(searchQuery);
                sui->DBDisplay->setModel(model);
                db.close();
                */
            } else {
                qDebug() << "query is not active";
                emit sendError(QString("query is not active"));
            }
        } else {
            qDebug() << "DB is not open";
            emit sendError(QString("DB is not open"));
        }
    } else {
        qDebug() << "DB is not valid";
        emit sendError(QString("DB is not valid"));
    }
    /*
    if (!db.open()){
        Erreur e(QString("Erreur ouverture de la base de donnee "));
        db.close();
    }
    */
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



