#ifndef DOSSIERMANAGER_H
#define DOSSIERMANAGER_H

#include "ErrorManager.h"
#include "./enumeration/enumeration.h"
#include "DBManager.h"
#include <QString>
#include <QVector>

/**
 * @brief The DBManager class
 *
 * DossierManager verefie que chaque entree d'uv dans la table inscription fait bien partie du cursus en cours de l'étudiant.
 *
 * A savoir sur SQlite :
 *  - SQLite does not have a separate Boolean storage class. Instead, Boolean values are stored as integers 0 (false) and 1 (true) [Voir : http://www.sqlite.org/datatype3.html ]
 *  -
 */

class DossierManager : public QObject
{
    Q_OBJECT
private:
    /* Debut SINGLETON */
    ///<DossierManager(const DossierManager &):dbm(DBManager::getInstance()){}
    DossierManager () ;
    void operator= (const DossierManager &){}
    ~DossierManager () ;
    friend class HandlerSingleton<DossierManager>;
    static HandlerSingleton<DossierManager> handler;
    /* Fin SINGLETON */
    DBManager & dbm;
public:
    /* Debut SINGLETON */
    static DossierManager & getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
    unsigned int getCreditsTotalEtu(const int id){return dbm.getCreditsTotalEtu(id);}
    unsigned int getCreditsCSEtu(const int id) {return dbm.getCreditsCategorie(id,enumeration::CS);}
    unsigned int getCreditsTMEtu(const int id) {return dbm.getCreditsCategorie(id,enumeration::TM);}
    unsigned int getCreditsTSHEtu(const int id) {return dbm.getCreditsCategorie(id,enumeration::TSH);}
    unsigned int getCreditsEqui(const int id) {return dbm.getCreditsEqui(id);}
    bool ajouteDossier(QString const & nom, QString const & prenom, enumeration::Civilite civ,
                   QString const & nationalite, QDate const dateDeNaissance, enumeration::Saison s, const int annee,
                   const int creditsEqui = 0, QString const cursus = NULL, const int numeroSemestre = 0,
                   const int nbCreditEtranger = 0);
signals:
    //! pour l'envoi d'erreur
    void sendError(QString e);
};

#endif // DOSSIERMANAGER_H
