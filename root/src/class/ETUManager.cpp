#include "ETUManager.h"

/* Debut partie SINGLETON */
HandlerSingleton<ETUManager> ETUManager::handler = HandlerSingleton<ETUManager> ();

ETUManager & ETUManager::getInstance(){
    if (!handler.instance)
        handler.instance = new ETUManager;
    return *handler.instance;
}

void ETUManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance = 0;
    }
}
/* Fin partie SINGLETON */

ETUManager::ETUManager() {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
}


ETUManager::~ETUManager(){
}

/*
bool ETUManager::isExistETU(const QString& name) const{
    DBManager & dbm = DBManager::getInstance();
    if(dbm.rechercheETU(name).isEmpty()){
        return false;
    }
    return true;
}

void ETUManager::ajouterETU(const QString& nom, const QString& prenom, enumeration::Civilite civ, QString& nationalite,QDate date){
    if (!isExistETU(nom)) {
        emit sendError(QString("Il existe deja cet etudiant"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.ajouteETU(nom,prenom,civ,nationalite,date);
    }
}

void ETUManager::modifierETU(const QString& nom,const QString& prenom, enumeration::Civilite civ, QString& nationalite,QDate date){
    if (!isExistETU(nom)) {
        emit sendError(QString("cet etudiant n'existe pas"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.modifieETU(nom,prenom,civ,nationalite,date);
    }
}


void ETUManager::supprimerETU(const QString& nom){
    if (!isExistETU(nom)) {
        emit sendError(QString("cet etudiant n'existe pas"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.supprimeETU(nom);
    }
}
*/
