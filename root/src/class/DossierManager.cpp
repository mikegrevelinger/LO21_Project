#include "DossierManager.h"

/* Debut partie SINGLETON */
HandlerSingleton<DossierManager> DossierManager::handler = HandlerSingleton<DossierManager> ();

DossierManager & DossierManager::getInstance(){
    if (!handler.instance)
        handler.instance = new DossierManager;
    return *handler.instance;
}

void DossierManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance = 0;
    }
}
/* Fin partie SINGLETON */

DossierManager::DossierManager():dbm(DBManager::getInstance()) {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
}


DossierManager::~DossierManager(){
}

bool DossierManager::ajouteDossier(QString const & nom, QString const & prenom, enumeration::Civilite civ,
               QString const & nationalite, QDate const dateDeNaissance, enumeration::Saison s, const int annee,
               const int creditsEqui, QString const cursus, const int numeroSemestre,
               const int nbCreditEtranger){
    if (dbm.getIdETU(nom,prenom,dateDeNaissance) == 0){
        emit sendError(QString("Deja existante"));
        return false;
    } else {
        return dbm.ajouteETU(nom,prenom,civ,nationalite,dateDeNaissance,s,annee,creditsEqui,cursus,numeroSemestre,nbCreditEtranger);
    }
}
