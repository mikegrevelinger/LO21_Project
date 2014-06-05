#include "DBmanager.h"


DBManager::DBManager() {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    /** Pour connaitre le chemin du repertoir courant de façon automatique */
    QString CurrentDir = QDir::currentPath();
    //reconstruction du chemin où se trouve la db
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","src/database/uvs.db");
    qDebug() << CurrentDir;
    db.setDatabaseName(CurrentDir);
    if (!db.isValid())
    {
        qDebug() << "Impossible de se connecter a la base de donnees";
        emit sendError(QString("Impossible de se connecter a la base de donnees"));
    }
}

DBManager::~DBManager(){
    db.close();
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

/*Debut UV */

QVector<QVector<QString> > & DBManager::rechercheUV(QString nom){
    QVector<QVector<QString> > *res = new QVector<QVector<QString> >;
    if (!openDB(db)) //impossible d'ouvrir
    {
        return *res;
    }
    QSqlQuery query;
    if (nom.size()<4){
        qDebug() <<"lol";
        query.prepare("SELECT * FROM uvs WHERE uvs.nom LIKE ?");
        query.addBindValue(QString("\%%1\%").arg(nom));
    } else {
        query.prepare("SELECT * FROM uvs WHERE uvs.nom = ?"); // la requete
        query.addBindValue(nom); //permet de remplacer le ? de query.prepare par nom
    }

    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans rechercheUV"));
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
    if (!openDB(db)) //impossible d'ouvrir
    {
        return *res;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM uvs WHERE uvs.Categorie = ?"); // la requete
    query.addBindValue(enumeration::CategorieUVToString(cat)); //permet de remplacer le ? de query.prepare par le QString de cat
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans rechercheUV"));
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

bool DBManager::ajouteUV(QString nom, enumeration::CategorieUV cat, int credits, QString d){
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO uvs (Nom,Categorie,Credits,Description) VALUES (?,?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(enumeration::CategorieUVToString(cat));
    query.addBindValue(QString::number(credits));
    query.addBindValue(d);
    if(!query.exec()) //pb lors de l'execution
    {
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::supprimeUV(QString nom) {
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("DELETE FROM uvs WHERE NOM = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        return false;
    }
    query.finish();
    return true;
}


bool DBManager::modifieUV(const QString & nom, enumeration::CategorieUV cat, unsigned int credits,const QString& d) {
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("UPDATE uvs SET categorie = ?, credits =?, description =? WHERE NOM = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(enumeration::CategorieUVToString(cat));
    query.addBindValue(QString::number(credits));
    query.addBindValue(d);
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        return false;
    }
    query.finish();
    return true;
}


int DBManager::getCreditsUV(const QString & nom){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getCreditsUV"));
        return -1; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT credits FROM uvs WHERE uvs.nom =?");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsUV"));
        return -1;
    }
    query.first();
    int res = query.value(0).toInt();
    query.finish();
    return res;
}

enumeration::CategorieUV DBManager::getCategorieUV(const QString & nom){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getCategorieUV"));
    }
    QSqlQuery query;
    query.prepare("SELECT categorie FROM uvs WHERE uvs.nom =?");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCategorieUV"));
    }
    query.first();
    QString res = query.value(0).toString();
    qDebug() <<res;
    query.finish();
    return enumeration::StringToCategorieUV(res);
}

QString DBManager::getDescriptionUV(const QString & nom){
    QString res = QString("");
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getDescriptionUV"));
        return res;
    }
    QSqlQuery query;
    query.prepare("SELECT description FROM uvs WHERE uvs.nom =?");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getDescriptionUV"));
        return res;
    }
    query.first();
    res = query.value(0).toString();
    query.finish();
    return res;
}

/* Fin UV */
bool DBManager::ajouteETU(QString const nom, QString const prenom, enumeration::Civilite civ, QString const nationalite, QDate const dateDeNaissance){
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO Etu (Nom,Prenom,Civilite,Nationalite,DateDeNaissance) VALUES (?,?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(enumeration::CiviliteToString(civ));
    query.addBindValue(nationalite);
    //query.addBindValue(dateDeNaissance);
    query.addBindValue(dateDeNaissance.toString("yyyyMMdd"));
    if(!query.exec()) //pb lors de l'execution
    {
        return false;
    }
    query.finish();
    return true;
}

QVector<QVector<QString> > & DBManager::rechercheETU(const QString nom){
    QVector<QVector<QString> > *res = new QVector<QVector<QString> >;
    if (!openDB(db)) //impossible d'ouvrir
    {
        return *res;
    }
    QSqlQuery query;

    query.prepare("SELECT * FROM Etu WHERE Etu.nom LIKE ?");
    query.addBindValue(QString("\%%1\%").arg(nom));

    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans rechercheUV"));
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

/*
CREATE TABLE "Etu" ("Nom" VARCHAR NOT NULL ,
                    "Prenom" VARCHAR NOT NULL ,
                    "Civilite" VARCHAR,
                    "Nationalite" VARCHAR,
                    "DateDeNaissance" DATETIME NOT NULL ,
                    PRIMARY KEY ("Nom", "Prenom", "DateDeNaissance"))
*/
