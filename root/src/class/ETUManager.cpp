#include "ETUManager.h"

    /* Debut partie SINGLETON */ /*
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
} */
/* Fin partie SINGLETON */


/*
ETUManager::~ETUManager(){
}

void ETUManager::ajouterETU(const QString& nom,const QString& prenom, enumation::civilite civ, QString& nationalite,Date date){
    if (ETUManager::rechercherETU(nom)) {
        emit sendError(QString("Il existe deja cet etudiant"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.ajouteETU(nom,prenom,civ,nationalite,date);
    }
} */
/*
void ETUManager::modifierETU(const QString& nom,const QString& prenom, enumation::civilite civ, QString& nationalite,Date date){
    if (!rechercherETU(nom)) {
        emit sendError(QString("cet etudiant n'existe pas"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.modifieETU(nom,prenom,civ,nationalite,date);
    }
} */

/*

bool ETUManager::rechercherETU(const QString& name)const{
        DBManager & dbm = DBManager::getInstance();
        if(dbm.rechercheETU(name).isEmpty()){
            return true;
        }else{
            return false;
        }
    }
}

/*
void ETUManager::supprimerETU(const QString& nom){
    if (!UVManager::rechercherETU(nom)) {
        emit sendError(QString("cet etudiant n'existe pas"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.supprimeETU(nom);
    }
}
*/
/*
ETUManager::ETUManager() {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
    /* FAUX
    if (!db.isValid())
    {
        qDebug() << "Impossible de se connecter a la base de donnees";
        emit sendError(QString("Impossible de se connecter a la base de donnees"));
    }
    */ /*
}
*/

