#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#include <QString>
#include <QObject>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QIODevice>
#include <QMessageBox>
#include <QDateTime>
#include "HandlerSingleton.h"
#include <QDebug>

/**
 * @brief ErrorManager : la classe qui gère les erreurs
 *
 * Cette classe reçoit toutes les erreurs envoyer par les différentes classes que nous avons codés.
 * Elle enregistre les erreurs dans un fichier log.txt sous le format : Error : NomDeLaCLasse : Texte de description de l'erreur : heure et date de l'erreu47
 * Ainsi, il est beaucoup plus facile de résoudre les différents problèmes rencontrés.
 * C'est une des premières classes crées.
 *
 */

class ErrorManager : public QObject
{
    Q_OBJECT
    /* Debut SINGLETON */
    ///<ErrorManager(const ErrorManager &){}
    ErrorManager () {}
    void operator= (const ErrorManager &){}
    ~ErrorManager () {}
    friend class HandlerSingleton<ErrorManager>;
    static HandlerSingleton<ErrorManager> handler;
    /* Fin SINGLETON */
public:
    /* Debut SINGLETON */
    static ErrorManager & getInstance();
    static void libererInstance();
    /* Fin SINGLETON */
signals:
    //Sera utiliser pour afficher un popMessage d'erreur
    void sendAfficheError(const QString & title, const QString & text);
public slots:
    //Pour traiter une erreur
    void mailBoxError(QString e);
};

#endif // ERRORMANAGER_H
