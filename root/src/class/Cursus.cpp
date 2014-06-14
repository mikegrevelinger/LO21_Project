#include "Cursus.h"

/* Debut Cursus */

/*
class CursusAvecObli : public Cursus {
public:
    ~CursusAvecObli();
    bool remplireCursus();
    void accept(class VisitorCursus &v);
};

class CursusAvecListUV : public Cursus {
public:
    ~CursusAvecListUV();
    bool remplireCursus();
    void accept(class VisitorCursus &v);
};

///Le decorateur pour ajouter des specificités aux classes
class CursusDecorator : public Cursus {
protected:
    Cursus * decorated;
    unsigned int nbCreditCS;
    unsigned int nbCreditTM;
    unsigned int nbCreditTSH;
    unsigned int nbCreditLibre;
public:
    CursusDecorator(Cursus * c) {decorated = c;}
    ~CursusDecorator() {delete decorated;}
    unsigned int getNbCreditsCS() const {return nbCreditCS;}
    unsigned int getNbCreditsTM() const {return nbCreditTM;}
    unsigned int getNbCreditsTSH() const {return nbCreditTSH;}
    unsigned int getNbCreditsLibre() const {return nbCreditLibre;}

    virtual bool remplireCursus() =0;
};

class CursusBranche : public CursusDecorator {
private:
    unsigned int nbCreditPCB;
    unsigned int nbCreditPSF;
public:
    CursusBranche(Cursus * c):CursusDecorator(c) {}
    ~CursusBranche();
    unsigned int getNbCreditsPCB() const {return nbCreditPCB;}
    unsigned int getNbCreditsPSF() const {return nbCreditPSF;}
    bool remplireCursus();///unsigned int getNbCreditsTotal() const {return nbCreditCS + nbCreditTM + nbCreditTSH + nbCreditLibre;}
};

class CursusTC : public CursusDecorator {
public:
    CursusTC(Cursus * c):CursusDecorator(c) {}
    ~CursusTC();
    bool remplireCursus();
};
*/

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


void Cursus::accept(class Visitor &v){

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

void CursusAvecObli::accept(class VisitorCursus &v){

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

void CursusAvecListUV::accept(class VisitorCursus &v){

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
    if (decorated->getTypeCursus() != enumeration::TypeBranche || decorated->getTypeCursus() != enumeration::TypeBrancheAvecUvObligatoire){
        emit sendError(QString("CursusBranche : Erreur entre le type et le nom dans remplireCursus"));
        return false;
    }
    CursusManager & cm = CursusManager::getInstance();

    /**
    for (int i = 0; i < listUV.size(); ++i) {
         if (cm.isFiliere(decorated->listeUV[i][0])){
             decorated->listUV[i].append(QString("Filiere"));
         }
         if (cm.isPCB(decorated->listeUV[i][0])){
             decorated->listUV[i].append(QString("PCB"));
         }
    }
    */

    DBManager & dbm = DBManager::getInstance();
    nbCreditCS = dbm.getNbCreditCSTC(nom);
    nbCreditTM = dbm.getNbCreditTMTC(nom);
    nbCreditTSH = dbm.getNbCreditTSHTC(nom);
    nbCreditLibre = dbm.getNbCreditLibreTC(nom);
    nbCreditPCB = dbm.getNbCreditPCB(nom);
    nbCreditPSF = dbm.getNbCreditPSF(nom);
    decorated->setNbCreditsTotal(nbCreditCS + nbCreditTM + nbCreditTSH + nbCreditLibre);
    decorated->setNbSemestre(dbm.getNbSemestreBranche(nom));
    return true;
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
    if (decorated->getTypeCursus() != enumeration::TypeTc || decorated->getTypeCursus() != enumeration::TypeBrancheAvecUvObligatoire){
        emit sendError(QString("CursusTC : Erreur entre le type et le nom dans remplireCursus"));
        return false;
    }
    nbCreditCS = dbm.getNbCreditCSTC(nom);
    nbCreditTM = dbm.getNbCreditTMTC(nom);
    nbCreditTSH = dbm.getNbCreditTSHTC(nom);
    nbCreditLibre = dbm.getNbCreditLibreTC(nom);
    decorated->setNbCreditsTotal(nbCreditCS + nbCreditTM + nbCreditTSH + nbCreditLibre);
    decorated->setNbSemestre(dbm.getNbSemestreBranche(nom));
    return true;
}

/* Fin CursusTC */
