#ifndef CURSUS_H
#define CURSUS_H

#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>


class CursusManager
{
private:
    /* Debut SINGLETON */
    CursusManager(const CursusManager &){}
    CursusManager () {}
    void operator= (const CursusManager &){}
    ~CursusManager () {}
    friend class HandlerSingleton<CursusManager>;
    static HandlerSingleton<CursusManager> handler;
    /* Fin SINGLETON */
public:
    /* Debut SINGLETON */
    static CursusManager & getInstance();
    static void libererInstance();
    /* Fin SINGLETON */

    void AssoObligatoire(QString& nom, QString& uv);
    void AssoNonObligatoire(QString& nom, QString& uv);
    void ajouterCursus(const QString& nom,const QString& description);
    void AjouterAsso(QString& nom,QString& uv);
};




#endif // CURSUS_H
