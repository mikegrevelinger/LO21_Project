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
