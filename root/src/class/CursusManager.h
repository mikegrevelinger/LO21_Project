#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>


class CursusManager : public QObject {
    Q_OBJECT
private:
    /* Debut SINGLETON */
    CursusManager ();
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
    bool isObligatoire(const QString & cur, const QString & nomUV, enumeration::TypeCursus Tcur);
signals:
    //!pour l'envoi d'erreur
    void sendError(QString e);
};




#endif // CURSUSMANAGER_H
