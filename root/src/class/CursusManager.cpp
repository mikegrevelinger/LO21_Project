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

bool CursusManager::isTypeTC(const QString &cursus)
{
    DBManager & dbm = DBManager::getInstance();
    if(dbm.getTypeCursus(cursus)==enumeration::TypeTc || dbm.getTypeCursus(cursus)==enumeration::TypeTcAvecUvObligatoire)
        return true;
    else
        return false;
}

bool CursusManager::isTypeBranche(const QString &cursus)
{
    DBManager &dbm = DBManager::getInstance();
    if(dbm.getTypeCursus(cursus)==enumeration::TypeBranche || dbm.getTypeCursus(cursus)==enumeration::TypeBrancheAvecUvObligatoire)
        return true;
    else
        return false;
}
