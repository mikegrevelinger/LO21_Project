#include "UVManager.h"


/* Debut partie SINGLETON */
HandlerSingleton<UVManager> UVManager::handler = HandlerSingleton<UVManager> ();

UVManager & UVManager::getInstance(){
    if (!handler.instance)
        handler.instance = new UVManager;
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance = 0;
    }
}
/* Fin partie SINGLETON */


UVManager::UVManager():dbm(DBManager::getInstance()) {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
}

UVManager::~UVManager(){
}

bool UVManager::isExistUV(const QString& name)const{
    if(dbm.rechercheUV(name).isEmpty()){
        return false;
    }
    return true;
}

/*
void UVManager::ajouterUV(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description){
    //if (dbm.rechercheUV(nom).isEmpty()) {
      //  emit sendError(QString("Deja existante"));
    //}else{
       dbm.ajouteUV(nom,cat,nbc,description);
    //}
}
*/
/*
void UVManager::modifierUV(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description){
    if (!isExistUV(nom)) {
        emit sendError(QString("existe pas"));
    }else{
       dbm.modifieUV(nom,cat,nbc,description);
    }
}
*/

/*
bool UVManager::rechercherUV(enumeration::CategorieUV cat)const{
    if(dbm.rechercheUV(cat).isEmpty()){
        return true;
    }else{
        return false;
    }
}
*/

void UVManager::supprimerUV(const QString& nom){
    if (!isExistUV(nom)) {
        emit sendError(QString("existe pas"));
    }else{
       dbm.supprimeUV(nom);
    }
}
