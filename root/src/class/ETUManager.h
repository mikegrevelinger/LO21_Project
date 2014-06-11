#ifndef ETUMANAGER_H
#define ETUMANAGER_H


#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>
#include <QDate>

#define q2c(string) string.toStdString()

class ETUManager : public QObject
{
    Q_OBJECT // utilisera des signaux
private:
    /* Debut SINGLETON */
    ETUManager(const ETUManager & e):dbm(e.dbm){}
    ETUManager () ;
    void operator= (const ETUManager & e){}
    ~ETUManager () ;
    friend class HandlerSingleton<ETUManager>;
    static HandlerSingleton<ETUManager> handler;
    /* Fin SINGLETON */
    DBManager & dbm;
    bool isExistETU(const QString& name)const;
public:
    /* Debut SINGLETON */
    static ETUManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
    void ajouterETU(const QString& nom,const QString& prenom, enumeration::Civilite civ, QString& nationalite, QDate date);
    void supprimerETU(const QString& nom); // on supprime selon le nom
    void modifierETU(const QString& nom,const QString& prenom, enumeration::Civilite civ, QString& nationalite, QDate date);
signals:
    void sendError(QString e);
};


#endif // ETUMANAGER_H
