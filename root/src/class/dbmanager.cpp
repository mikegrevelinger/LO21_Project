#include "DBmanager.h"


DBManager::DBManager() {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
    db_uvs = QSqlDatabase::addDatabase("QSQLITE");
    db_uvs.setHostName("localhost");
    db_uvs.setUserName("root");
    db_uvs.setPassword("");
    /** Pour connaitre le chemin du repertoir courant de façon automatique */
    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","src/database/uvs.db");
    qDebug() << CurrentDir;
    db_uvs.setDatabaseName(CurrentDir);
    if (!db_uvs.isValid())
    {
        qDebug() << "Impossible de se connecter a la base de donnees";
        emit sendError(QString("Impossible de se connecter a la base de donnees"));
    }
}

DBManager::~DBManager(){
    db_uvs.close();
}


/* Debut partie SINGLETON */

//Construction et acces au singleton DBManager
HandlerSingleton<DBManager> DBManager::handler = HandlerSingleton<DBManager> ();

DBManager & DBManager::getInstance(){
    if (!handler.instance)
        handler.instance = new DBManager;
    return *handler.instance;
}

//Destruction du singleton DBManager
void DBManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
    handler.instance = 0;
    }
}
/* Fin partie SINGLETON */


/*Debut UV */

//Fonction d'ouverture d'un base de donnee o
bool DBManager::openDB(QSqlDatabase & o){
    if (!o.open()) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Impossible d'ouvrir %1.").arg(o.databaseName()));
        o.close();
        return false;
    }
    return true;
}

//Pour connaitre le nombre de colonne de la requete q
int DBManager::queryNbColonne(QSqlQuery & q){
    QSqlRecord rec = q.record();
    int nb_col = rec.count(); // pour savoir le nombre de colonne
    return nb_col;
}


QVector<QVector<QString> > & DBManager::rechercheUV(QString nom){
    QVector<QVector<QString> > *res = new QVector<QVector<QString> >;
    if (!openDB(db_uvs)) //impossible d'ouvrir
    {
        return *res;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM uvs WHERE uvs.nom = ?"); // la requete
    query.addBindValue(nom); //permet de remplacer le ? de query.prepare par nom
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete"));
        return *res;
    }
    int nb_col = queryNbColonne(query); // pour savoir le nombre de colonne
    while (query.next())//parcourir toutes les lignes
    {
        QVector<QString> vect;
        for (int i = 0; i< nb_col;i++){
            qDebug() <<query.value(i).toString();
            vect.append(query.value(i).toString());
        }
        res->append(vect);
    }
    query.finish();
    return *res;
}

QVector<QVector<QString> > & DBManager::rechercheUV(enumeration::CategorieUV cat){
    QVector<QVector<QString> > *res = new QVector<QVector<QString> >;
    if (!openDB(db_uvs)) //impossible d'ouvrir
    {
        return *res;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM uvs WHERE uvs.Categorie = ?"); // la requete
    query.addBindValue(enumeration::CategorieUVToString(cat)); //permet de remplacer le ? de query.prepare par le QString de cat
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete"));
        return *res;
    }
    int nb_col = queryNbColonne(query); // pour savoir le nombre de colonne
    while (query.next())//parcourir toutes les lignes
    {
        QVector<QString> vect;
        for (int i = 0; i< nb_col;i++){
            qDebug() <<query.value(i).toString();
            vect.append(query.value(i).toString());
        }
        res->append(vect);
    }
    query.finish();
    return *res;
}
