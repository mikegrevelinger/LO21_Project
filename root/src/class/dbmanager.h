#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "HandlerSingleton.h"

class DBManager
{
private:
    /* Debut SINGLETON */
    DBManager(const DBManager &){}
    DBManager(){} // Rien a initialiser pour l'instant
    void operator= (const DBManager &){}
    ~DBManager(){} // Rien de particulier à faire pour l'instant
    friend class HandlerSingleton<DBManager>;
    static HandlerSingleton<DBManager> handler;
    /* Fin SINGLETON */
public:
    /* Debut SINGLETON */
    static DBManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
};

#endif // DBMANAGER_H
