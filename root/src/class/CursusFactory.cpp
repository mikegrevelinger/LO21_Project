#include "CursusFactory.h"

Cursus * CursusFactory::makeCursus(const QString & nomCursus) {
    DBManager & dbm = DBManager::getInstance();
    enumeration::TypeCursus t  = dbm.getTypeCursus(nomCursus);
    switch(t){
    case enumeration::TypeTc: return new CursusTC(new Cursus) ;
    case enumeration::TypeTcAvecUvObligatoire: return new CursusTC(new CursusAvecObli) ;
    case enumeration::TypeBranche: return new CursusBranche(new Cursus) ;
    case enumeration::TypeBrancheAvecUvObligatoire: return new CursusBranche(new CursusAvecObli) ;
    default: return NULL;
    }
    return NULL;
}

Cursus * CursusFactory::makeCursus(const int id){
    DBManager & dbm = DBManager::getInstance();
    return makeCursus(dbm.getCursusEtu(id));
}

CursusFactory::CursusFactory() {

}

CursusFactory::~CursusFactory() {

}
