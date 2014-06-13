#ifndef CURSUS_H
#define CURSUS_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QStringList>
#include "DBManager.h"
#include "VisitorCursus.h"

class Cursus {
protected:
    QString nom;
    QList<QStringList> listUV;
    unsigned int nbSemestre;
    unsigned int nbCreditsTotal;
    enumeration::TypeCursus t;
public:
    const QString & getNom() const {return nom;}
    const QList<QStringList> & getListUV() const {return listUV;}
    unsigned int getNbSemestre() const {return nbSemestre;}
    virtual unsigned int getNbCreditsTotal() const {return nbCreditsTotal;}
    bool remplireCursus();
    virtual void accept(class Visitor &v);
    virtual ~Cursus();
};

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

#endif // CURSUS_H
