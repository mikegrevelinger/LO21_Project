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
    /*
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
    */
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
/* Debut METHODE PRIVEE */
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

/* Fin METHODE PRIVEE */
/* Debut UV */

QList<QStringList > & DBManager::rechercheUV(QString nom){
    QList<QStringList > *res = new QList<QStringList >;
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
        QStringList vect;
        for (int i = 0; i< nb_col;i++){
            qDebug() <<query.value(i).toString();
            vect.append(query.value(i).toString());
        }
        res->append(vect);
    }
    query.finish();
    return *res;
}

QList<QStringList > & DBManager::rechercheUV(enumeration::CategorieUV cat){
    QList<QStringList > *res = new QList<QStringList >;
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
        QStringList vect;
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
        return enumeration::ErrorCategorieUV;
    }
    QSqlQuery query;
    query.prepare("SELECT categorie FROM uvs,categorieUV WHERE uvs.nom =? AND uvs.nom = categorieUV.uv");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCategorieUV"));
        return enumeration::ErrorCategorieUV;
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
        return enumeration::ErrorSaison;
    }
    QSqlQuery query;
    query.prepare("SELECT SemestreEnseigne FROM uvs WHERE uvs.nom =?");
    query.addBindValue(uv);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getSaisonUV"));
        return enumeration::ErrorSaison;
    }
    query.first();
    QString res = query.value(0).toString();
    query.finish();
    return enumeration::StringToSaison(res);
}

/* Fin UV */
/* Debut ETU */

bool DBManager::ajouteETU(const QString &nom, const QString &prenom, enumeration::Civilite civ,
                          const QString &nationalite, QDate const dateDeNaissance, enumeration::Saison s,
                          const int annee, const int creditsEqui, const QString cursus, const int numeroSemestre,
                          const int nbCreditEtranger){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour ajouteETU"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO dossier (NomEtu,PrenomEtu,Civilite,Nationalite,DateDeNaissance,SemestreCourant, \
                  anneeCourante,nbCreditEquivalence,CursusCourant,numeroSemestre,\
                  nbCreditEtranger) VALUES (?,?,?,?,?,?,?,?,?,?,?)");
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
    query.addBindValue(nbCreditEtranger);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteETU"));
        return false;
    }
    query.finish();
    return true;
}

QList<QStringList > & DBManager::rechercheETU(const QString nom, const QString prenom){
    QList<QStringList > *res = new QList<QStringList >;
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
        QStringList vect;
        for (int i = 0; i< nb_col;i++){
            qDebug() <<query.value(i).toString();
            vect.append(query.value(i).toString());
        }
        res->append(vect);
    }
    query.finish();
    return *res;
}

QList<QStringList > & DBManager::rechercheETU(const QString & s){
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

bool DBManager::ajouteInscription(int const & id, QString const & uv, enumeration::Note n, const int annee, enumeration::Saison s){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        return false;
    }
    /*
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
    */
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

unsigned int DBManager::getCreditsEqui(const int id){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getCreditsEqui"));
        return -1; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT nbCreditEquivalence FROM Dossier WHERE dossier.id =? ");
    query.addBindValue(id);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsEqui"));
        return -1;
    }
    query.first();
    unsigned int res = query.value(0).toInt();
    query.finish();
    return res;
}

unsigned int DBManager::getCreditsTotalEtu(const int id){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getCreditsTotal"));
        return -1; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT SUM(credit) AS Somme from inscription, uvs, categorieUv WHERE inscription.IDetu = ? AND inscription.NomUv = uvs.Nom AND uvs.nom = CategorieUv.Uv AND (inscription.Note = 'A' OR inscription.Note = 'B' OR inscription.Note = 'C' OR inscription.Note = 'D' OR inscription.Note = 'E');");
    query.addBindValue(id);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTotal"));
        return -1;
    }
    query.first();
    unsigned int res = query.value(0).toInt();
    query.finish();
    res += getCreditsEqui(id);
    return res;
}

unsigned int DBManager::getCreditsCategorie(const int id,enumeration::CategorieUV c){
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getCreditsTotal"));
        return -1; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT SUM(credit) AS Somme from inscription, uvs, categorieUv WHERE inscription.IDetu = ? AND inscription.NomUv = uvs.Nom AND uvs.nom = CategorieUv.Uv AND CategorieUv.Categorie= ? AND (inscription.Note = 'A' OR inscription.Note = 'B' OR inscription.Note = 'C' OR inscription.Note = 'D' OR inscription.Note = 'E');");
    query.addBindValue(id);
    query.addBindValue(enumeration::CategorieUVToString(c));
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTotal"));
        return -1;
    }
    query.first();
    unsigned int res = query.value(0).toInt();
    query.finish();
    return res;
}

QStringList & DBManager::getInscription(const int id)
{
    QStringList *UVInscrit = new QStringList;
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getInscription"));
        return *UVInscrit;
    }
    QSqlQuery query;
    query.prepare("Select NomUv FROM Inscription where Inscription.id=? and Inscription.Note='INSCRIT'"); // la requete pour avoir toutes les uvs inscrites.
    query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiant
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getInscription"));
        return *UVInscrit;
    }
    while (query.next())//parcourir toutes les lignes
    {
        qDebug() <<query.value(0).toString();
        UVInscrit->append(query.value(0).toStringList());
    }
    query.finish();
    return *UVInscrit;
}

QStringList & DBManager::getUvsEnCours(const int id)
{
    QStringList * UVEnCours = new QStringList;
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getUvsEnCours"));
        return *UVEnCours;
    }
    QSqlQuery query;
    query.prepare("Select NomUv FROM Inscription where Inscription.id=? and Inscription.Note='EC'"); // la requete pour avoir toutes les uvs en cours.
    query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiant
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getUvsEnCours"));
        return *UVEnCours;
    }
    while (query.next())//parcourir toutes les lignes
    {
        qDebug() <<query.value(0).toString();
        UVEnCours->append(query.value(0).toStringList());
    }
    query.finish();
    return *UVEnCours;
}

QString & DBManager::getCursusEtu(const int id){
    QString * cur = new QString;
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCursusEtu"));
        return *cur;
    }
    QSqlQuery query;
    query.prepare("Select CursusCourant FROM Dossier WHERE dossier.id=?"); // la requete pour avoir toutes les uvs en cours.
    query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiant
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCursusEtu"));
        return *cur;
    }
    query.first();
    *cur = query.value(0).toString();
    query.finish();
    return *cur;
}

/* Fin ETU */
/* Debut Cursus */

bool DBManager::ajouteBranche(const QString & nom, const QString & descri, const int creditCS,
                   const int creditTM, const int creditTSH, const int creditLibre, const int creditPCB,
                   const int creditPSF, const int nbSemestre){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour ajouteBranche"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO dossier VALUES (?,?,?,?,?,?,?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(descri);
    query.addBindValue(creditCS);
    query.addBindValue(creditTM);
    query.addBindValue(creditTSH);
    query.addBindValue(creditLibre);
    query.addBindValue(creditPCB);
    query.addBindValue(creditPSF);
    query.addBindValue(nbSemestre);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteBranche"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::ajouteTC (const QString & nom, const QString & descri, const int creditCS,
               const int creditTM, const int creditTSH, const int creditLibre, const int nbSemestre) {
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour ajouteTC"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO dossier VALUES (?,?,?,?,?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(descri);
    query.addBindValue(creditCS);
    query.addBindValue(creditTM);
    query.addBindValue(creditTSH);
    query.addBindValue(creditLibre);
    query.addBindValue(nbSemestre);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteTC"));
        return false;
    }
    query.finish();
    return true;
}

bool DBManager::ajouteMineur (const QString & nom, const QString & descri, const int nbListe){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour ajouteMineur"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO dossier VALUES (?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(descri);
    query.addBindValue(nbListe);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteMineur"));
        return false;
    }
    query.finish();
    return true;
}


enumeration::TypeCursus DBManager::getTypeCursus(const QString & nom){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getTypeCursus"));
        return enumeration::ErrorTypeCursus;
    }
    QSqlQuery query;
    // la requete
    query.prepare("SELECT uv FROM tcPourUV WHERE tcPourUV.nomCursus = ? AND tcPourUV.obligatoire = 0");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getTypeCursus"));
        return enumeration::ErrorTypeCursus;
    }
    QString res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return enumeration::TypeTc;
    }
    query.prepare("SELECT uv FROM tcPourUV WHERE tcPourUV.nomCursus = ? AND tcPourUV.obligatoire = 1");
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getTypeCursus"));
        return enumeration::ErrorTypeCursus;
    }
    res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return enumeration::TypeTcAvecUvObligatoire;
    }
    if (!res.isEmpty()){
        return enumeration::TypeTc;
    }
    query.prepare("SELECT uv FROM BranchePourUv WHERE BranchePourUv.nom = ? AND tcPourUV.obligatoire = 0");
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getTypeCursus"));
        return enumeration::ErrorTypeCursus;
    }
    res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return enumeration::TypeBranche;
    }
    query.prepare("SELECT uv FROM BranchePourUv WHERE BranchePourUv.nom = ? AND tcPourUV.obligatoire = 1");
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getTypeCursus"));
        return enumeration::ErrorTypeCursus;
    }
    res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return enumeration::TypeBrancheAvecUvObligatoire;
    }
    return enumeration::ErrorTypeCursus;
}

/* Fin Cursus */
