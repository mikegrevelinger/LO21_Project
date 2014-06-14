#ifndef PREVISION_H
#define PREVISION_H

#include "DBManager.h"
#include "CursusFactory.h"
#include "Cursus.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <QStringList>


class IStrategie
{
public:
    virtual void execute() = 0; /// execute() est une fonction virtuelle pure et de ce fait IStrategie est une classe abstraite autrement dit une classe qui ne peut être instanciée
};



class PrevisionTC: public IStrategie
{
private:
    Cursus * cur;
public:
    PrevisionTC(const int idEtu, const QString & nom);
    bool isObligatoireUv(QStringList &ListUV);
    QList<QString>  NewList(Cursus& cur, const int &id);
    void prevision(Cursus& cur,const int id);
    bool benefique(const QString &UV,const int &nbCreditCSActuel,const int &nbCreditTMActuel,const int &nbCreditTSHActuel,const QString &cursus);
};

class PrevisionBranche:public IStrategie
{
private:

public:

};


class Element
{
private:
        IStrategie* strategie;

public:
        Element(IStrategie* strategie) : strategie(strategie)
        {
        }

        void execute()
        {
                strategie->execute();
        }
};




#endif // PREVISION_H
