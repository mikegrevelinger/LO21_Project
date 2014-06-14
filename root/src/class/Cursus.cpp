#include "Cursus.h"

/* Debut Cursus */

Cursus::Cursus():listUV(*(new QList<QStringList>)) {
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
}

bool Cursus::remplireCursus(const QString & n){
    nom = n;
    DBManager & dbm = DBManager::getInstance();
    t = dbm.getTypeCursus(nom);
    if (t == enumeration::ErrorTypeCursus){
        emit sendError(QString("Cursus : ErrorTypeCursus dans remplireCursus"));
        return false;
    }
    QStringList & s = dbm.getListeUV(n,t);
    if (s.isEmpty()){
        emit sendError(QString("Cursus : liste vide dans remplireCursus"));
        return false;
    }
    for (int i = 0; i < s.size(); ++i){
        QStringList * tmp = new QStringList;
        tmp->append(s.at(i));
        listUV.append(*tmp);
    }
    nbCreditsTotal = 0;
    nbSemestre = 0;
    return true;
}


int Cursus::accept(VisitorCursus &v){
    return v.visit(this);
}

Cursus::~Cursus(){
    for (int i = 0; i < listUV.size(); ++i) {
         listUV[i].clear();
    }
    listUV.clear();
}

/* Fin Cursus */
/* Debut CursusAvecObli */

CursusAvecObli::CursusAvecObli():Cursus() {
}

int CursusAvecObli::accept(class VisitorCursus &v){
    return v.visit(this);
}

bool CursusAvecObli::remplireCursus(const QString &n){
    nom = n;
    DBManager & dbm = DBManager::getInstance();
    CursusManager & cm = CursusManager::getInstance();
    t = dbm.getTypeCursus(nom);
    if (t == enumeration::ErrorTypeCursus){
        emit sendError(QString("Cursus : ErrorTypeCursus dans remplireCursus"));
        return false;
    }
    QStringList & s = dbm.getListeUV(n,t);
    if (s.isEmpty()){
        emit sendError(QString("Cursus : liste vide dans remplireCursus"));
        return false;
    }
    for (int i = 0; i < s.size(); ++i){
        QStringList * tmp = new QStringList;
        tmp->append(s.at(i));
        if (cm.isObligatoire(nom,s.at(i),t)){
            tmp->append(QString("Obligatoire"));
        }
        listUV.append(*tmp);
    }
    nbCreditsTotal = 0;
    nbSemestre = 0;
    return true;
}

CursusAvecObli::~CursusAvecObli(){
    for (int i = 0; i < listUV.size(); ++i) {
         listUV[i].clear();
    }
    listUV.clear();
}

/* Fin CursusAvecObli */
/* Debut CursusAvecListUV */

CursusAvecListUV::CursusAvecListUV():Cursus(){

}

CursusAvecListUV::~CursusAvecListUV(){
    for (int i = 0; i < listUV.size(); ++i) {
         listUV[i].clear();
    }
    listUV.clear();
}

int CursusAvecListUV::accept(class VisitorCursus &v){
    return v.visit(this);
}

/* Fin CursusAvecListUV */
/* Debut CursusDecorator */

CursusDecorator::CursusDecorator(Cursus * dec){
    decorated = dec;
}

CursusDecorator::~CursusDecorator(){
    for (int i = 0; i < listUV.size(); ++i) {
         listUV[i].clear();
    }
    listUV.clear();
    delete decorated;
}

/* Fin CursusDecorator */
/* Debut CursusBranche */

CursusBranche::~CursusBranche() {
    for (int i = 0; i < listUV.size(); ++i) {
         listUV[i].clear();
    }
    listUV.clear();
}

bool CursusBranche::remplireCursus(const QString & n){
    if (!decorated->remplireCursus(n)){
        return false;
    }
    if (decorated->getTypeCursus() != enumeration::TypeBranche && decorated->getTypeCursus() != enumeration::TypeBrancheAvecUvObligatoire){
        emit sendError(QString("CursusBranche : Erreur entre le type et le nom dans remplireCursus"));
        return false;
    }
    DBManager & dbm = DBManager::getInstance();
    for (int i = 0; i < listUV.size(); ++i) {
         if (dbm.isUVFiliere(decorated->getNom(),decorated->listUV[i][0])){
             decorated->listUV[i].append(QString("Filiere"));
         }
         if (dbm.isPCB(decorated->getNom(),decorated->listUV[i][0])){
             decorated->listUV[i].append(QString("PCB"));
         }
    }
    nbCreditCS = dbm.getNbCreditCSTC(decorated->getNom());
    nbCreditTM = dbm.getNbCreditTMTC(decorated->getNom());
    nbCreditTSH = dbm.getNbCreditTSHTC(decorated->getNom());
    nbCreditLibre = dbm.getNbCreditLibreTC(decorated->getNom());
    nbCreditPCB = dbm.getNbCreditPCB(decorated->getNom());
    nbCreditPSF = dbm.getNbCreditPSF(decorated->getNom());
    decorated->setNbCreditsTotal(nbCreditCS + nbCreditTM + nbCreditTSH + nbCreditLibre);
    decorated->setNbSemestre(dbm.getNbSemestreBranche(decorated->getNom()));
    return true;
}

int CursusBranche::accept(VisitorCursus &v){
    return v.visit(this);
}

/* Fin CursusBranche */
/* Debut CursusTC */

CursusTC::~CursusTC() {
    for (int i = 0; i < listUV.size(); ++i) {
         listUV[i].clear();
    }
    listUV.clear();
    delete decorated;
}

bool CursusTC::remplireCursus(const QString & n){
    DBManager & dbm = DBManager::getInstance();
    if (!decorated->remplireCursus(n)){
        return false;
    }
    if (decorated->getTypeCursus() != enumeration::TypeTc && decorated->getTypeCursus() != enumeration::TypeBrancheAvecUvObligatoire){
        emit sendError(QString("CursusTC : Erreur entre le type et le nom dans remplireCursus"));
        return false;
    }
    nbCreditCS = dbm.getNbCreditCSTC(decorated->getNom());
    nbCreditTM = dbm.getNbCreditTMTC(decorated->getNom());
    nbCreditTSH = dbm.getNbCreditTSHTC(decorated->getNom());
    nbCreditLibre = dbm.getNbCreditLibreTC(decorated->getNom());
    decorated->setNbCreditsTotal(nbCreditCS + nbCreditTM + nbCreditTSH + nbCreditLibre);
    decorated->setNbSemestre(dbm.getNbSemestreBranche(decorated->getNom()));
    return true;
}

int CursusTC::accept(VisitorCursus &v){
    return v.visit(this);
}

/* Fin CursusTC */
