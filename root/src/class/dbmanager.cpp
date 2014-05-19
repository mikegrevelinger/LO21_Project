#include "dbmanager.h"

/*Debut partie SINGLETON */
HandlerSingleton<DBManager> DBManager::handler = HandlerSingleton<DBManager>();

DBManager & DBManager::getInstance(){
    if (!handler.instance)
        handler.instance = new DBManager;
    return *handler.instance;
}

void DBManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance=0;
    }
}
/*Fin partie SINGLETON */
