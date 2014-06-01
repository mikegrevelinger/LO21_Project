#ifndef UVMANAGER_H
#define UVMANAGER_H

#include "HandlerSingleton.h"
#include "ErrorManager.h"
#include "DBManager.h"
#include "./enumeration/enumeration.h"
#include <QString>
#include <QVector>
#include <QObject>

#define q2c(string) string.toStdString()

class UVManager : public QObject
{
    Q_OBJECT // utilisera des signaux
private:

    QVector<QVector<QString> > rechercheUV(const QString& c) const;
    void operator=(const UVManager);
    /* Debut SINGLETON */
    UVManager(const UVManager &){}
    UVManager () ;
    void operator= (const UVManager &){}
    ~UVManager () ;
    friend class HandlerSingleton<UVManager>;
    static HandlerSingleton<UVManager> handler;
    /* Fin SINGLETON */

    /** Ajouter un isEmpty pour un <QVector .... */
public:
    /* Debut SINGLETON */
    static UVManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
    void ajouterUV(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description);
    void supprimerUV(const QString& nom);
    void modifierUV(const QString& nom, enumeration::CategorieUV cat, unsigned int nbc,const QString& description);
    bool rechercherUV(const QString& name)const;
    bool rechercherUV(enumeration::CategorieUV cat)const;
signals:
    void sendError(QString e);
};


#endif // UVMANAGER_H


