#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "ErrorManager.h"
#include "./enumeration/enumeration.h"
#include <QtSql>
#include <QString>
#include <QVector>
#include <QDate>
#include <QStringList>
#include <QList>

#define q2c(string) string.toStdString()

/**
 * @brief DBManager : l'unique classe qui interroge la base de donnée
 *
 * Cette classe permet d'obtenir une abstraction entre l'implémentation des données (comment c'est sauvergarder; pour nous tout en BDD avec SQLite mais cela aurait pu être dans des fichiers XML, ...)
 * Ainsi, nous suivons le design pattern Bridge (http://en.wikipedia.org/wiki/Bridge_pattern).
 *
 * Cette classe effectue uniquement des requêtes, sans vérifier ce qu'il lui est envoyé et sans traiter les données.
 *
 */

class DBManager : public QObject
{
    Q_OBJECT
private:
    /* Debut SINGLETON */
    ///<DBManager(const DBManager &){} : D'après quelques recherces : QObject does not support copying. It's copy constructor is not public.
    DBManager () ;
    void operator= (const DBManager &){}
    ~DBManager () ;
    friend class HandlerSingleton<DBManager>;
    static HandlerSingleton<DBManager> handler;
    /* Fin SINGLETON */
    QSqlDatabase db;
    bool openDB(QSqlDatabase & o);///<Pour connaitre le nombre de colonne de la requete q
    int queryNbColonne(QSqlQuery & q);///<Pour connaitre le nombre de ligne de la requete q
    int queryNbLigne (QSqlQuery & q);///<Revient au même que size() qui n'est pas implementer par SQLITE
public:
    /* Debut SINGLETON */
    static DBManager& getInstance();
    static void libererInstance();
    /* Fin SINGLETON */

    /* Debut UV */
    QList<QStringList > & rechercheUV(QString nom);
    ///<Permet de rechercher des uv en fonctions du nom de l'UV. Cette fonction est capable de retourner toutes les UV qui ont un nom formé de certaine lettre.
    QList<QStringList > & rechercheUV(enumeration::CategorieUV cat);
    bool ajouteUV(const QString & nom, enumeration::CategorieUV cat, enumeration::Saison s, const int credits, const QString & d); ///< Renvoie true si ajout effectué, false sinon
    bool ajouteCategorieUV(const QString & nom, enumeration::CategorieUV cat, const int credits);///< Renvoie true si ajout effectué, false sinon. Est implementee meme si on ne l'utilise jamais.
    bool supprimeUV(QString nom); ///< Renvoie true si suprression effectuée, false sinon
    bool modifieDescriptionUV(const QString & nom, const QString& d); ///< Renvoie true si modification effectuée, false sinon. Cette classe ne peut pas modifier le nom (comme "NF92") d'une UV
    int getCreditsUV(const QString & nom);///< Renvoie -1 en cas d'erreur, sinon bonne valeur
    enumeration::CategorieUV getCategorieUV(const QString & nom);
    QString getDescriptionUV(const QString & nom);///< Renvoie un QString vide en cas d'erreur, sinon bonne valeur
    enumeration::Saison getSaisonUV(const QString & uv);
    bool isEnseigne(const QString& UV,enumeration::Saison semestre);
    /* Fin UV */

    /* Debut ETUDIANT */
    QList<QStringList > & rechercheETU(const QString & s);
    QList<QStringList > & rechercheETU(const QString nom, const QString prenom);
    bool ajouteETU(QString const & nom, QString const & prenom, enumeration::Civilite civ,
                   QString const & nationalite, QDate const dateDeNaissance, enumeration::Saison s, const int annee,
                   const int creditsEqui = 0, QString const cursus = NULL, const int numeroSemestre = 0,
                   const int nbCreditEtranger = 0, QString const & Fil = NULL);
    int getIdETU (QString const & nom, QString const & prenom = "", QDate const & date = QDate());
    bool ajouteInscription(int const & id, QString const & uv, enumeration::Note n, const int annee, enumeration::Saison s);
    ///< ajouteInscription : modifie les valeurs du dossier etudiant (les nbCredits) + ajoute une ligne à la table Inscription
    unsigned int getCreditsEqui(const int id);
    unsigned int getCreditsTotalEtu(const int id);
    unsigned int getCreditsCategorie(const int id,enumeration::CategorieUV c);
    QStringList & getInscription(const int id);
    QStringList & getUvsEnCours(const int id);
    QString & getCursusEtu(const int id);
    enumeration::Saison getSemestreActuel(const int id);
    int getAnneeActuelETU(const int id);
    bool isUVInscrit(const QString& UV, const int& id);
    /* Fin ETUDIANT */

    /*Debut CURSUS */
    bool ajouteBranche(const QString & nom, const QString & descri, const int creditCS,
                       const int creditTM, const int creditTSH, const int creditLibre, const int creditPCB,
                       const int creditPSF, const int nbSemestre);
    bool isPCB(const QString &cursus, const QString &uv);
    bool ajouteTC (const QString & nom, const QString & descri, const int creditCS,
                   const int creditTM, const int creditTSH, const int creditLibre, const int nbSemestre);
    bool ajouteMineur (const QString & nom, const QString & descri, const int nbListe);
    enumeration::TypeCursus getTypeCursus(const QString & nom); ///<Le cursus doit avoir au moins une UV enregistré pour que cette fonction retourne un type correct
    bool isObligatoireTC(const QString & cursus, const QString & UV); ///< Renvoie true si l'uv est obligatoire(Pour un cursus TC), false sinon
    bool isObligatoireBranche(const QString & cursus, const QString & UV); ///< Renvoie true si l'uv est obligatoire(Pour un cursus Branche), false sinon
    bool isObligatoireMineur(const QString & cursus, const QString & UV); ///< Renvoie true si l'uv est obligatoire pour un Mineur donné, false sinon
    bool isInList(const QString & cursus, const QString & UV, unsigned int i); ///< Pour savoir si une UV apartient à une Liste donnée
    int getNbCreditCSBranche(const QString cursus);
    int getNbCreditTMBranche(const QString cursus);
    int getNbCreditTSHBranche(const QString cursus);
    int getNbCreditLibreBranche(const QString cursus);
    int getNbSemestreBranche(const QString cursus);
    int getNbCreditPCB(const QString cursus);
    int getNbCreditPSF(const QString cursus);
    int getNbCreditCSTC(const QString cursus);
    int getNbCreditTMTC(const QString cursus);
    int getNbCreditTSHTC(const QString cursus);
    int getNbCreditLibreTC(const QString cursus);
    int getNbSemestreTC (const QString cursus);
    QStringList & getListeUV(const QString & cursus, enumeration::TypeCursus Tcur = enumeration::ErrorTypeCursus);
    /* Fin CURSUS */

    /* Debut choix */
    bool NewUvREJ(const QString UV,const int id); ///<Permet de modifier/Ajouter le choix d'une UV à REJ
    bool NewUvVEUT(const QString UV, const int id); ///< Permet de modifier/Ajouter le choix d'une UV à VEUT
    enumeration::Choix getChoix(const QString & nom, const int &id);///< Renvoit le choix pour une UV donnée d'un étudiant
    /* Fin choix */

    /* Debut pour Prevision */
    bool inscriptionUValide(const int id, const QString UV, const int annee, enumeration::Saison semestre); ///< Permet d'inscrire les UVS selectionnées et validées par l'étudiant lors de la prévision
    bool AnnulationPrevision(const int id);
    /* Fin pour Prevision */

    /*Debut pour filiere */
    bool ajouteFiliere (const QString & nom, const QString & descri, const int nbCredit, const QString &cursus);
    QString getNomCursusFiliere(const QString &nom);
    QString getDescriptionFiliere(const QString & nom);
    bool isFiliere(const QString &nom);
    bool isUVFiliere(const QString &nom, const QString &UV);
    /* Fin pour Filiere */

signals:
    //!pour l'envoi d'erreur
    void sendError(QString e);
};

#endif // DBMANAGER_H
