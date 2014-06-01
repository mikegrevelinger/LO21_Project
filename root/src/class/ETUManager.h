#ifndef ETUMANAGER_H
#define ETUMANAGER_H


#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>

#define q2c(string) string.toStdString()
/*
class ETUManager : public QObject
{
    Q_OBJECT // utilisera des signaux
private:

    QVector<QVector<QString> > rechercheETU(const QString& c) const; // on recherche un etu par son nom.
    void operator=(const ETUManager);
    //friend struct Handler;
    //static Handler handler; */
    /* Debut SINGLETON */ /*
    ETUManager(const ETUManager &){}
    ETUManager () ;
    void operator= (const ETUManager &){}
    ~ETUManager () ;
    friend class HandlerSingleton<ETUManager>;
    static HandlerSingleton<ETUManager> handler;*/
    /* Fin SINGLETON */

    /* Ajouter un isEmpty pour un <QVector .... */ /*
public: */
    /* Debut SINGLETON */ /*
    static ETUManager& getInstance();
    static void libererInstance(); */
    /* Fin SINGLETON */ /*
    void ajouterETU(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description);
    //void supprimerETU(const QString& nom); // on supprime selon le nom
    //void modifierETU(const QString& nom,const QString& prenom, enumation::civilite civ, QString& nationalite,Date date);
    bool rechercherETU(const QString& name)const;
signals:
    void sendError(QString e);
};

*/

#endif // ETUMANAGER_H
