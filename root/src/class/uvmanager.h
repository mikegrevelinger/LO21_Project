#ifndef UVMANAGER_H
#define UVMANAGER_H

#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>
#include "./gui/rechercheInstantaneUV.h"

#define q2c(string) string.toStdString()

class UVManager : public QObject
{
    Q_OBJECT // utilisera des signaux
private:
    /* Debut SINGLETON */
    ///<UVManager(const UVManager &) {}
    UVManager () ;
    void operator= (const UVManager &){}
    ~UVManager () ;
    friend class HandlerSingleton<UVManager>;
    static HandlerSingleton<UVManager> handler;
    /* Fin SINGLETON */
    DBManager & dbm;
    bool isExistUV(const QString& name) const;
public:
    /* Debut SINGLETON */
    static UVManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
    void ajouterUV(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description);
    void supprimerUV(const QString& nom);
    void modifierUV(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description);
signals:
    void sendError(QString e);
};


#endif // UVMANAGER_H


