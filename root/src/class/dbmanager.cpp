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
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","src/database/bdd.sqlite");
    qDebug() << CurrentDir;
    db.setDatabaseName(CurrentDir);
    if (!db.isValid())
    {
        qDebug() << "Impossible de se connecter a la base de donnees";
        emit sendError(QString("Impossible de se connecter a la base de donnees"));
    }
    qDebug() <<"lol";
    if (!openDB(db)) //impossible d'ouvrir
    {
        qDebug() << "17";
    }
    QSqlQuery query;
    if(!query.exec("PRAGMA foreign_keys=ON;")) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur PRAGMA"));
    }
    if(!query.exec("PRAGMA foreign_keys;")) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur PRAGMA"));
    }
    query.first();
    qDebug() << query.value(0).toString();
    if(!query.exec("SELECT sqlite_version()")) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur PRAGMA"));
    }
    query.first();
    qDebug() << query.value(0).toString();
}

DBManager::~DBManager(){
    db.close();
}


/*Debut partie SINGLETON */
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

//Pour connaitre le nombre de ligne de la requete q
int DBManager::queryNbLigne(QSqlQuery &q){
    int nombre = 0;
    while(q.next()){
           nombre++;
    }
    return nombre;
}

bool DBManager::modifieCreditsTotalEtu(const int id, const int n){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : Impossible d\'ouvrir BDD dans modifieDescriptionUV"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("UPDATE dossier SET nbCreditsTotal = ? WHERE dossier.id = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(n);
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans modifieDescriptionUV"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::modifieCreditsCSEtu(const int id, const int n){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : Impossible d\'ouvrir BDD dans modifieCreditsCSEtu"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("UPDATE dossier SET nbCreditCS = ? WHERE dossier.id = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(n);
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans modifieCreditsCSEtu"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::modifieCreditsTMEtu(const int id, const int n){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : Impossible d\'ouvrir BDD dans modifieCreditsTMEtu"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("UPDATE dossier SET nbCreditTM = ? WHERE dossier.id = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(n);
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans modifieCreditsTMEtu"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::modifieCreditsTSHEtu(const int id, const int n){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : Impossible d\'ouvrir BDD dans modifieCreditsTSHEtu"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.addBindValue(n);
    query.prepare("UPDATE dossier SET nbCreditTSH = ? WHERE dossier.id = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans modifieCreditsTSHEtu"));
        return false;
    }
    query.finish();
    return true;
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
        query.prepare("SELECT nom,categorie,credit,description FROM uvs, categorieUV WHERE uvs.nom LIKE ? AND uvs.nom = categorieUV.uv;");
        query.addBindValue(QString("\%%1\%").arg(nom));
    } else {
        query.prepare("SELECT nom,categorie,credit,description FROM uvs, categorieUV WHERE uvs.nom = ? AND uvs.nom = categorieUV.uv;");
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
    query.prepare("SELECT nom,categorie,credit,description FROM uvs, categorieUV WHERE uvs.nom = categorieUV.uv AND uvs.Categorie = ?"); // la requete
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

bool DBManager::ajouteUV(const QString & nom, enumeration::CategorieUV cat, enumeration::Saison s, const int credits, const QString & d){
    if (!openDB(db)) {
        qDebug() <<"1";
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO uvs (Nom,SemestreEnseigne,Description) VALUES (?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(s);
    query.addBindValue(d);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete 1 dans ajouteUV"));
        return false;
    }
    query.finish();
    query.prepare("INSERT INTO CategorieUV (Categorie,Uv,Credit) VALUES (?,?,?)");
    query.addBindValue(enumeration::CategorieUVToString(cat));
    query.addBindValue(nom);
    query.addBindValue(credits);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete 2 dans ajouteUV"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::ajouteCategorieUV(const QString & nom, enumeration::CategorieUV cat, const int credits){
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO CategorieUV (Categorie,Uv,Credit) VALUES (?,?,?)");
    query.addBindValue(enumeration::CategorieUVToString(cat));
    query.addBindValue(nom);
    query.addBindValue(credits);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteCategorieUV"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::supprimeUV(QString nom) {
    if (!openDB(db)) {
        qDebug() <<"1";
        return false;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM categorieUV WHERE uv = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete 1 dans supprimeUV"));
        return false;
    }
    query.finish();
    query.prepare("DELETE FROM uvs WHERE nom = ?");
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete 2 dans supprimeUV"));
        return false;
    }
    query.finish();
    return true;
}


bool DBManager::modifieDescriptionUV(const QString & nom, const QString& d) {
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("UPDATE uvs SET description = ? WHERE NOM = ?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(d);
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans modifieDescriptionUV"));
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
    query.prepare("SELECT credits FROM uvs, categorieUV WHERE uvs.nom =? AND uvs.nom = categorieUV.uv");
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
    query.prepare("SELECT categorie FROM uvs,categorieUV WHERE uvs.nom =? AND uvs.nom = categorieUV.uv");
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

enumeration::Saison DBManager::getSaisonUV(const QString & uv){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getSaisonUV"));
    }
    QSqlQuery query;
    query.prepare("SELECT SemestreEnseigne FROM uvs WHERE uvs.nom =?");
    query.addBindValue(uv);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getSaisonUV"));
    }
    query.first();
    QString res = query.value(0).toString();
    query.finish();
    return enumeration::StringToSaison(res);
}

/* Fin UV */
/*Debut ETU */
bool DBManager::ajouteETU(const QString &nom, const QString &prenom, enumeration::Civilite civ,
                          const QString &nationalite, QDate const dateDeNaissance, enumeration::Saison s,
                          const int annee, const int creditsEqui, const QString cursus, const int numeroSemestre, const int creditsTOTAL,
                          const int creditsCS, const int creditsTM, const int creditsTSH, const int nbCreditEtranger){
    if (!openDB(db)) {
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO dossier (NomEtu,PrenomEtu,Civilite,Nationalite,DateDeNaissance,SemestreCourant, \
                  anneeCourante,nbCreditEquivalence,CursusCourant,numeroSemestre,nbCreditsTotal,nbCreditCs,nbCreditTm,nbCreditTSH,\
                  nbCreditEtranger) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(enumeration::CiviliteToString(civ));
    query.addBindValue(nationalite);
    query.addBindValue(dateDeNaissance);
    query.addBindValue(enumeration::SaisonToString(s));
    query.addBindValue(annee);
    query.addBindValue(creditsEqui);
    query.addBindValue(cursus);
    query.addBindValue(numeroSemestre);
    query.addBindValue(creditsTOTAL);
    query.addBindValue(creditsCS);
    query.addBindValue(creditsTM);
    query.addBindValue(creditsTSH);
    query.addBindValue(nbCreditEtranger);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteETU"));
        return false;
    }
    query.finish();
    return true;
}

QVector<QVector<QString> > & DBManager::rechercheETU(const QString nom, const QString prenom){
    QVector<QVector<QString> > *res = new QVector<QVector<QString> >;
    if (!openDB(db)) //impossible d'ouvrir
    {
        return *res;
    }
    QSqlQuery query;

    query.prepare("SELECT * FROM dossier WHERE dossier.nomETU LIKE ? OR dossier.prenomEtu LIKE ?;");
    query.addBindValue(QString("\%%1\%").arg(nom));
    query.addBindValue(QString("\%%1\%").arg(prenom));
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

QVector<QVector<QString> > & DBManager::rechercheETU(const QString & s){
    return rechercheETU(s,s);
}

int DBManager::getIdETU (QString const & nom, QString const & prenom, QDate const & date){
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Impossible d'ouvrir BDD dans getIdETU"));
        return 0;
    }
    QSqlQuery query;
    if (prenom.isEmpty() && date.isNull()){
        qDebug() <<1;
        query.prepare("SELECT id FROM dossier WHERE dossier.nomETU = ?;");
        query.addBindValue(nom);
    }
    if (prenom.isEmpty() && !date.isNull()){
        qDebug() <<2;
        query.prepare("SELECT id FROM dossier WHERE dossier.nomETU = ? AND dossier.dateDeNaissance = ?;");
        query.addBindValue(nom);
        query.addBindValue(date);
    }
    if (!prenom.isEmpty() && date.isNull()){
        qDebug() <<3;
        query.prepare("SELECT id FROM dossier WHERE dossier.nomETU = ? AND dossier.prenomETU = ?;");
        query.addBindValue(nom);
        query.addBindValue(prenom);
    }
    if (!prenom.isEmpty() && !date.isNull()){
        qDebug() <<4;
        query.prepare("SELECT id FROM dossier WHERE dossier.nomETU = ? AND dossier.prenomETU = ? AND dossier.dateDeNaissance = ?;");
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(date);
    }
    if(!query.exec()) //pb lors de l'execution
    {
        qDebug() <<5;
        emit sendError(QString("DBManager : Erreur execution de la requete dans rechercheUV"));
        return 0;
    }
    if (queryNbLigne(query)!=1){
        qDebug() <<"Aucun ou plus d'un id pour ces informations.";
        return 0;
    }
    query.first();
    int res = query.value(0).toInt();
    query.finish();
    return res;
}

int DBManager::getCreditsTotalEtu(const int id){
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Impossible d'ouvrir BDD dans getCreditsTotalEtu"));
        return 0;
    }
    QSqlQuery query;
    query.prepare("SELECT nbCreditsTotal FROM dossier WHERE dossier.id = ?;");
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTotalEtu"));
        return 0;
    }
    query.first();
    int res = query.value(0).toInt();
    query.finish();
    return res;
}

int DBManager::getCreditsCSEtu(const int id){
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Impossible d'ouvrir BDD dans getCreditsCSEtu"));
        return 0;
    }
    QSqlQuery query;
    query.prepare("SELECT nbCreditCS FROM dossier WHERE dossier.id = ?;");
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsCSEtu"));
        return 0;
    }
    query.first();
    int res = query.value(0).toInt();
    query.finish();
    return res;
}

int DBManager::getCreditsTMEtu(const int id){
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Impossible d'ouvrir BDD dans getCreditsTMEtu"));
        return 0;
    }
    QSqlQuery query;
    query.prepare("SELECT nbCreditTM FROM dossier WHERE dossier.id = ?;");
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTMEtu"));
        return 0;
    }
    query.first();
    int res = query.value(0).toInt();
    query.finish();
    return res;
}

int DBManager::getCreditsTSHEtu(const int id){
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Impossible d'ouvrir BDD dans getCreditsTSHEtu"));
        return 0;
    }
    QSqlQuery query;
    query.prepare("SELECT nbCreditTSH FROM dossier WHERE dossier.id = ?;");
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTSHEtu"));
        return 0;
    }
    query.first();
    int res = query.value(0).toInt();
    query.finish();
    return res;
}



bool DBManager::ajouteInscription(int const & id, QString const & uv, enumeration::Note n, const int annee, enumeration::Saison s){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        return false;
    }

    int creditTot =0;
    int creditAutre = 0;
    enumeration::CategorieUV c = getCategorieUV(uv);
    switch(c){
        case enumeration::CS:
            creditTot = getCreditsUV(uv) + getCreditsTotalEtu(id);
            creditAutre = getCreditsUV(uv) + getCreditsCSEtu(id);
            if (!modifieCreditsTotalEtu(id,creditTot)){
                emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (Total)"));
                return false;
            }
            if (!modifieCreditsCSEtu(id,creditAutre)){
                emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (CS)"));
                return false;
            }
            break;
        case enumeration::TM: return "TM";
            creditTot = getCreditsUV(uv) + getCreditsTotalEtu(id);
            creditAutre = getCreditsUV(uv) + getCreditsTMEtu(id);
            if (!modifieCreditsTotalEtu(id,creditTot)){
                emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (Total)"));
                return false;
            }
            if (!modifieCreditsTMEtu(id,creditAutre)){
                emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (TM)"));
                return false;
            }
            break;
        case enumeration::TSH: return "TSH";
            creditTot = getCreditsUV(uv) + getCreditsTotalEtu(id);
            creditAutre = getCreditsUV(uv) + getCreditsTSHEtu(id);
            if (!modifieCreditsTotalEtu(id,creditTot)){
                emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (Total)"));
                return false;
            }
            if (!modifieCreditsTSHEtu(id,creditAutre)){
                emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (TSH)"));
                return false;
            }
            break;
    default: return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO inscription VALUES (?,?,?,?,?);");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(id);
    query.addBindValue(uv);
    query.addBindValue(enumeration::NoteToString(n));
    query.addBindValue(annee);
    query.addBindValue(enumeration::SaisonToString(s));
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteInscription (Inscription)"));
        return false;
    }
    query.finish();
    return true;
}

/* Fin ETU */
