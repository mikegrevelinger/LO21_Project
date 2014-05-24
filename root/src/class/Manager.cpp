#include "Manager.h"

/* Debut partie SINGLETON */
template<typename T>
HandlerSingleton<T> Manager<T>::handler = HandlerSingleton<T> ();

template<typename T>
T & Manager<T>::getInstance(){
    if (!handler.instance)
        handler.instance = new T;
    return *handler.instance;
}

template<typename T>
void Manager<T>::libererInstance(){
    if (handler.instance){
        delete handler.instance;
    handler.instance = 0;
    }
}
/* Fin partie SINGLETON */
