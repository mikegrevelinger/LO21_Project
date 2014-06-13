#ifndef CURSUS_H
#define CURSUS_H

#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>


class CursusManager {
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
    bool isTypeTC(const QString & n);
    bool isTypeBranche(const QString & n);
};




#endif // CURSUS_H
