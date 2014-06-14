#include "CursusManager.h"
#include "DBManager.h"

CursusManager::CursusManager() {
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
}

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

bool CursusManager::isObligatoire(const QString & cur, const QString & nomUV, enumeration::TypeCursus Tcur){
    DBManager & dbm = DBManager::getInstance();
    if (Tcur == enumeration::ErrorTypeCursus){
        emit sendError(QString("CursusManager : Erreur de cursus dans isObligatoire"));
        return false;
    } else if (Tcur == enumeration::TypeBranche || Tcur == enumeration::TypeTc){
        return false;
    } else if (Tcur == enumeration::TypeTcAvecUvObligatoire){
        return dbm.obligatoireTC(cur,nomUV);
    } else if (Tcur == enumeration::TypeBrancheAvecUvObligatoire) {
        return dbm.obligatoireBranche(cur,nomUV);
    }
    emit sendError(QString("CursusManager : Arrive à un endroit inapproprié dans isObligatoire"));
    return false;
}
