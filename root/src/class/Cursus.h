#ifndef CURSUS_H
#define CURSUS_H

#include "CursusManager.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <QStringList>
#include "VisitorCursus.h"
#include "ErrorManager.h"


/**
 * @brief The Cursus class
 *
 * Cette classe cursus est un attribut de Prevision et n'est utilisé que par cette class (construite par CursusFactory).
 * Elle facilite le travail de prevision (on n'aurait pu faire sans cette classe Cursus).
 *
 * Cursus suit le design pattern decorator pour pouvoir ajouter de nouvelles fonctions dynamiquement.
 *
 */

class Cursus : public QObject {
    Q_OBJECT
protected:
    QString nom;
    QList<QStringList> & listUV;
    unsigned int nbSemestre;
    unsigned int nbCreditsTotal;
    enumeration::TypeCursus t;
    friend class CursusBranche;
public:
    Cursus();
    virtual ~Cursus();
    virtual const QString & getNom() const {return nom;}
    virtual const QList<QStringList> & getListUV() const {return listUV;}
    virtual unsigned int getNbSemestre() const {return nbSemestre;}
    virtual unsigned int getNbCreditsTotal() const {return nbCreditsTotal;}
    virtual enumeration::TypeCursus getTypeCursus() const {return t;}
    void setNbSemestre(unsigned int nb) {nbSemestre = nb;}
    void setNbCreditsTotal (unsigned int nb) {nbCreditsTotal = nb;}
    virtual int accept(class VisitorCursus &v);///<Utiliser par le design pattern Visitor
    virtual bool remplireCursus(const QString & n);
signals:
    void sendError(QString e);//!Signal utilisé pour envoyer une erreur à ErrorManager
};

class CursusAvecObli : public Cursus {
public:
    ~CursusAvecObli();
    CursusAvecObli();
    bool remplireCursus(const QString & n);
    int accept(class VisitorCursus & v);///<Utiliser par le design pattern Visitor
};

class CursusAvecListUV : public Cursus {
public:
    ~CursusAvecListUV();
    CursusAvecListUV();
    int accept(class VisitorCursus &v);
    bool remplireCursus(const QString & n) {nom = n; return false;}
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
    CursusDecorator(Cursus * dec);
    virtual ~CursusDecorator();

    unsigned int getNbCreditsCS() const {return nbCreditCS;}
    unsigned int getNbCreditsTM() const {return nbCreditTM;}
    unsigned int getNbCreditsTSH() const {return nbCreditTSH;}
    unsigned int getNbCreditsLibre() const {return nbCreditLibre;}

    ///Renvoi les gets des fonctions du Cursus decorated
    const QString & getNom() const {return decorated->getNom();}
    const QList<QStringList> & getListUV() const {return decorated->getListUV();}
    unsigned int getNbSemestre() const {return decorated->getNbSemestre();}
    unsigned int getNbCreditsTotal() const {return decorated->getNbCreditsTotal();}
    enumeration::TypeCursus getTypeCursus() const {return decorated->getTypeCursus();}
    virtual int accept(class VisitorCursus &v) =0;
    virtual bool remplireCursus(const QString & n)= 0;
};

class CursusBranche : public CursusDecorator {
private:
    QString nomFiliere;
    unsigned int nbCreditPCB;
    unsigned int nbCreditPSF;
public:
    CursusBranche(Cursus * c):CursusDecorator(c) {}
    ~CursusBranche();
    unsigned int getNbCreditsPCB() const {return nbCreditPCB;}
    unsigned int getNbCreditsPSF() const {return nbCreditPSF;}
    const QString & getNomFiliere() const {return nomFiliere;}
    bool remplireCursus(const QString & n);
    int accept(class VisitorCursus &v);
};

class CursusTC : public CursusDecorator {
public:
    CursusTC(Cursus * c):CursusDecorator(c) {}
    bool remplireCursus(const QString & n);
    ~CursusTC();
    int accept(class VisitorCursus &v);
};

#endif // CURSUS_H
