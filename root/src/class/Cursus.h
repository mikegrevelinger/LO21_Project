#ifndef CURSUS_H
#define CURSUS_H
/*
#include <QObject>
#include <QString>
#include <QVector>
#include <QStringList>
#include "DBManager.h"

class Cursus {
protected:
    QString nom;
    QString description;
    QStringList listUV;
public:
    Cursus(const QString & n, const QString & d):nom(n),description(d){}
    const QString & getNom() const {return nom;}
    const QString & getDescription() const {return description;}
    virtual bool remplireList();
    virtual ~Cursus {};
};

class CursusObli : public Cursus {
public:
    ~CursusObli(){}
    CursusObli(const QString & n) : Cursus(n,d){}
    bool remplireList();
};

class CursusMineur : public Cursus {
};

class CursusDecorator : Cursus {
protected:
    Cursus decorated;
public:
    CursusDecorator(const Cursus c):decorated(c){}
    ~CursusDecorator() {}
};

class CursusBranche : public CursusDecorator {
private:
    unsigned int nbCreditCS;
    unsigned int nbCreditTM;
    unsigned int nbCreditTSH;
    unsigned int nbCreditLibre;
    unsigned int nbCreditPCB;
    unsigned int nbCreditPSF;
    unsigned int nbSemestre;
    QStringList listUvPCB;

public:
    ~CursusBranche() {}
    CursusBranche(const Cursus c, const unsigned int cs, const unsigned int tm, const unsigned int tsh,
                  const unsigned int libre, const unsigned int pcb, const unsigned int psf,
                  const unsigned int semestre):decorated(c),nbCreditCS(cs),nbCreditTM(tm),
        nbCreditTSH(tsh),nbCreditLibre(libre),nbCreditPCB(pcb),nbCreditPSF(psf),nbSemestre(semestre) {}
    unsigned int getNbCreditsCS() const {return nbCreditCS;}
    unsigned int getNbCreditsTM() const {return nbCreditTM;}
    unsigned int getNbCreditsTSH() const {return nbCreditTSH;}
    unsigned int getNbCreditsLibre() const {return nbCreditLibre;}
    unsigned int getNbCreditsPCB() const {return nbCreditPCB;}
    unsigned int getNbCreditsPSF() const {return nbCreditPSF;}
    unsigned int getNbSemestre() const {return nbSemestre;}
    bool remplireList();
};

class CursusTC : public CursusDecorator {
private:
    unsigned int nbCreditCS;
    unsigned int nbCreditTM;
    unsigned int nbCreditTSH;
    unsigned int nbCreditLibre;
    unsigned int nbSemestre;
public:
    ~CursusTC() {}
    CursusTC(const Cursus c, const unsigned int cs, const unsigned int tm, const unsigned int tsh,
                  const unsigned int libre, const unsigned int semestre):decorated(c),nbCreditCS(cs),nbCreditTM(tm),
        nbCreditTSH(tsh),nbCreditLibre(libre),nbSemestre(semestre) {}
    unsigned int getNbCreditsCS() const {return nbCreditCS;}
    unsigned int getNbCreditsTM() const {return nbCreditTM;}
    unsigned int getNbCreditsTSH() const {return nbCreditTSH;}
    unsigned int getNbCreditsLibre() const {return nbCreditLibre;}
    unsigned int getNbSemestre() const {return nbSemestre;}
};
*/
#endif // CURSUS_H
