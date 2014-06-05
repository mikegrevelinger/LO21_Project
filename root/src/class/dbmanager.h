#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "ErrorManager.h"
#include "./enumeration/enumeration.h"
#include <QtSql>
#include <QString>
#include <QVector>

#define q2c(string) string.toStdString()

/**
 * @brief The DBManager class
 *
 * modifieUV ne peut pas modifier le nom d'une UV.
 */

class DBManager : public QObject
{
    Q_OBJECT
private:
    /* Debut SINGLETON */
    //DBManager(const DBManager &){}
    DBManager () ;
    void operator= (const DBManager &){}
    ~DBManager () ;
    friend class HandlerSingleton<DBManager>;
    static HandlerSingleton<DBManager> handler;
    /* Fin SINGLETON */
    QSqlDatabase db;
    bool openDB(QSqlDatabase & o);
    int queryNbColonne(QSqlQuery & q);
public:
    /* Debut SINGLETON */
    static DBManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
    /* Debut UV */
    QVector<QVector<QString> > & rechercheUV(QString nom);
    ///<Permet de rechercher des uv en fonctions du nom de l'UV. Cette fonction est capable de retourner toutes les UV qui ont un nom formé de certaine lettre.
    QVector<QVector<QString> > & rechercheUV(enumeration::CategorieUV cat);
    bool ajouteUV(QString nom, enumeration::CategorieUV cat, int credits, QString d); ///< Renvoie true si ajout effectué, false sinon
    bool supprimeUV(QString nom); ///< Renvoie true si suprression effectuée, false sinon
    bool modifieUV(const QString & nom, enumeration::CategorieUV cat, unsigned int credits, const QString& d); ///< Renvoie true si modification effectuée, false sinon
    int getCreditsUV(const QString & nom);///< Renvoie -1 en cas d'erreur, sinon bonne valeur
    enumeration::CategorieUV getCategorieUV(const QString & nom);
    QString getDescriptionUV(const QString & nom);///< Renvoie un QString vide en cas d'erreur, sinon bonne valeur
    /*Fin UV */
signals:
    //pour l'envoi d'erreur
    void sendError(QString e);
};

#endif // DBMANAGER_H
