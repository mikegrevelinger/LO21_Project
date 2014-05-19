#ifndef HANDLERSINGLETON_H
#define HANDLERSINGLETON_H

/**
 * DESIGN PATTERN SINGLETON debut
 *
 * HandlerSingleton sert a verifier si la classe a deja ete instancie ou pas
 *
 * HandlerSingleton doit etre friend de la classe Manager
 * code : friend struct HandlerSingleton< ... >;
 *
 * On definit dans la classe un static Handler qui sera initialisé dans le .cpp du Manager
 * code : static HandlerSingleton< ... > handler;
 * ex : code : UVManager::Handler UVManager::handler=Handler(); --> pour l'initialisation
 *
 * Le constructeur de recopie [ex : UVManager(const UVManager &);] +
 * l'operateur = [ ex : void operator=(const UVManager&);] +
 * le constructeur vide UVManager(); +
 * le destructeur ~UVManager();
 * doivent être dans la partie PRIVEE !!
 * --> Ils peuvent etre redefini
 *
 * Pour la création et la destruction, on utlisera deux fonctions static :
 * ex : code : static UVManager& getInstance();
 * ex : code : static void libererInstance();
 * On les definirera dans .cpp du Manager
 * ex : code :
 *
UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager;
    return *handler.instance;
}
 * ex : code :
void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}
 *
 * DESIGN PATTERN SINGLETON fin
 */

template<typename ManagerType>
class HandlerSingleton{
public:
    ManagerType * instance;
    HandlerSingleton():instance(0){}
    ~HandlerSingleton(){ if (instance) delete instance; instance=0; }
};

#endif // HANDLERSINGLETON_H
