#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "ErrorManager.h"
#include <QtSql>
#include <QString>

#define q2c(string) string.toStdString()

class DBManager : public QObject
{
    Q_OBJECT
private:
    /* Debut SINGLETON */
    //DBManager(const DBManager &){}
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
signals:
    void sendError(QString e);
};

#endif // DBMANAGER_H
