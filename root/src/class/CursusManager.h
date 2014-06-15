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
    bool isTypeTC(const QString & n);///< Renvoie true si le cursus est de Type TC, false sinon
    bool isTypeBranche(const QString & n);///< Renvoie true si le cursus est de Type Branche, false sinon
    bool isObligatoire(const QString & cur, const QString & nomUV, enumeration::TypeCursus Tcur);///< Renvoie true si l'uv d'un Cursus donné est obligatoire, false sinon
signals:
    //!pour l'envoi d'erreur
    void sendError(QString e);
};




#endif // CURSUSMANAGER_H
