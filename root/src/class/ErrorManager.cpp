#include "ErrorManager.h"

/* Debut partie SINGLETON */
HandlerSingleton<ErrorManager> ErrorManager::handler = HandlerSingleton<ErrorManager> ();

ErrorManager & ErrorManager::getInstance(){
    if (!handler.instance)
        handler.instance = new ErrorManager;
    return *handler.instance;
}

void ErrorManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
    handler.instance = 0;
    }
}
/* Fin partie SINGLETON */

void ErrorManager::mailBoxError(QString e){
    QDateTime date = QDateTime::currentDateTimeUtc();
    QFile fichier("log.txt");
    //Ouverture en écriture + lecture
    //Le curseur sera à la fin du fichier
    //Juste pour signaler que ce sera du text
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
    {
        QTextStream flux (&fichier);
        flux <<"\nError: "<<e<<" -- Time: "<<date.toString();
        fichier.close();
    } else {
        qDebug() <<"lol";
    }
}
