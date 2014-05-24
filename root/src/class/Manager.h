#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "HandlerSingleton.h"

/*
 * Classe abstraite, base de tous les Manager en singleton.
 * Le signal permet de notifier des erreurs à ErrorManager
*/

class Singleton
{
    public:
        static Singleton& getInstance()
        {
             if(!instance)
                 instance= new Singleton;
             return *instance;
        }
        static void freeInstance()
        {
            delete instance;
            instance = NULL;
        }
    private:
        static Singleton *instance;
};

template<typename T>
class Manager : public QObject
{
protected:
    /* Debut SINGLETON */
    Manager(const Manager &){}
    Manager ();
    void operator= (const Manager &){}
    ~Manager ();
    static HandlerSingleton<T> handler;
    /* Fin SINGLETON */
public:
    /* Debut SINGLETON */
    static T & getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
};

#endif // MANAGER_H
