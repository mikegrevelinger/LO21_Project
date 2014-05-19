#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "HandlerSingleton.h"
#include "ErrorDB.h"
#include <QtSql>

#define q2c(string) string.toStdString()

class DBManager
{
private:
    /* Debut SINGLETON */
    DBManager(const DBManager &){}
    DBManager () ;
    void operator= (const DBManager &){}
    ~DBManager () ;
    friend class HandlerSingleton<DBManager>;
    static HandlerSingleton<DBManager> handler;
    /* Fin SINGLETON */
    QSqlDatabase db;
public:
    /* Debut SINGLETON */
    static DBManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
};

#endif // DBMANAGER_H
