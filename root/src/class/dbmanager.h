#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "ErrorManager.h"
#include "./enumeration/enumeration.h"
#include <QtSql>
#include <QString>
#include <QVector>

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
    QSqlDatabase db_uvs;
    bool openDB(QSqlDatabase & o);
    int queryNbColonne(QSqlQuery & q);
public:
    /* Debut SINGLETON */
    static DBManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
    /* Debut UV */
    QVector<QVector<QString> > & rechercheUV(QString nom);
    QVector<QVector<QString> > & rechercheUV(enumeration::CategorieUV cat);
signals:
    //pour l'envoi d'erreur
    void sendError(QString e);
};

#endif // DBMANAGER_H
