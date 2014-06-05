#include "CursusManager.h"
#include "DBManager.h"



/* Debut partie SINGLETON */
HandlerSingleton<CursusManager> CursusManager::handler = HandlerSingleton<CursusManager> ();

CursusManager & CursusManager::getInstance(){
    if (!handler.instance)
        handler.instance = new CursusManager;
    return *handler.instance;
}

void CursusManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance = 0;
    }
}
/* Fin partie SINGLETON */


/*
void CursusManager::AssoObligatoire(QString& nom, QString& uv){
    DBManager & dbm = DBManager::getInstance();
    dbm.ajouteAsso(nom,uv,1);
}


void CursusManager::AssoNonObligatoire(QString& nom, QString& uv){
    DBManager & dbm = DBManager::getInstance();
    dbm.ajouteAsso(nom,uv,0);
}

void CursusManager::AjouterCursus(QString& nom,QString& uv){
    DBManager& dbm = DBManager::getInstance();
    dbm.ajouteCursus(nom,uv);
}

void CursusManager::AjouterAsso(QString& nom,QString& uv){
    DBManager& dbm = DBManager::getInstance();
    dbm.ajouteAsso(nom,uv);
}
*/
