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


int DBManager::queryNbColonne(QSqlQuery & q){
    QSqlRecord rec = q.record();
    int nb_col = rec.count(); // pour savoir le nombre de colonne
    return nb_col;
}


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

bool DBManager::isEnseigne(const QString& UV,enumeration::Saison semestre){
   QString ress;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return false;
   }
   QSqlQuery query;
   query.prepare("select SemestreEnseigne FROM Uvs where Uvs.Nom=?"); // la requete pour obtenir le semestre ou elle est enseignée
   query.addBindValue(UV); //permet de remplacer le ? de query.prepare par le nom de l'uv
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans enseigne"));
       return 0;
   }
   query.first();
   ress=query.value(0).toString();
   enumeration::Saison res;
   res=enumeration::StringToSaison(ress);
   if(res==semestre || res==enumeration::Tout)
   {
   return true;
   }
   else
   {
       return false;
   }
   query.finish();
}

/* Fin UV */
/* Debut ETU */

bool DBManager::ajouteETU(const QString &nom, const QString &prenom, enumeration::Civilite civ,
                          const QString &nationalite, QDate const dateDeNaissance, enumeration::Saison s,
                          const int annee, const int creditsEqui, const QString cursus, const int numeroSemestre,
                          const int nbCreditEtranger, const QString & Fil){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour ajouteETU"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO dossier (NomEtu,PrenomEtu,Civilite,Nationalite,DateDeNaissance,SemestreCourant, \
                  anneeCourante,nbCreditEquivalence,CursusCourant,numeroSemestre,\
                  nbCreditEtranger,Filiere) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)");
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
    query.addBindValue(Fil);
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

    query.prepare("SELECT ID,NomEtu,PrenomEtu,Civilite,Nationalite,DateDeNaissance FROM dossier WHERE dossier.nomETU LIKE ? OR dossier.prenomEtu LIKE ?;");
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
        return 0; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT nbCreditEquivalence FROM Dossier WHERE dossier.id =? ");
    query.addBindValue(id);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsEqui"));
        return 0;
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
        return 0; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT SUM(credit) AS Somme from inscription, uvs, categorieUv WHERE inscription.IDetu = ? AND inscription.NomUv = uvs.Nom AND uvs.nom = CategorieUv.Uv AND (inscription.Note = 'A' OR inscription.Note = 'B' OR inscription.Note = 'C' OR inscription.Note = 'D' OR inscription.Note = 'E');");
    query.addBindValue(id);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTotal"));
        return 0;
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
        return 0; // -1 pour dire qu'il y a une erreur.
    }
    QSqlQuery query;
    query.prepare("SELECT SUM(credit) AS Somme from inscription, uvs, categorieUv WHERE inscription.IDetu = ? AND inscription.NomUv = uvs.Nom AND uvs.nom = CategorieUv.Uv AND CategorieUv.Categorie= ? AND (inscription.Note = 'A' OR inscription.Note = 'B' OR inscription.Note = 'C' OR inscription.Note = 'D' OR inscription.Note = 'E');");
    query.addBindValue(id);
    query.addBindValue(enumeration::CategorieUVToString(c));
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getCreditsTotal"));
        return 0;
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

enumeration::Saison DBManager::getSemestreActuel(const int id)
{
   if (!openDB(db)) //impossible d'ouvrir
   {
       return enumeration::ErrorSaison;
   }
   QSqlQuery query;
   query.prepare("select SemestreCourant FROM Dossier where Dossier.ID=?"); // la requete pour avoir le numero du semestre Actuel
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiants
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getSemestreActuel"));
       return enumeration::ErrorSaison;;
   }
   query.first();
   enumeration::Saison res;
   res=enumeration::StringToSaison(query.value(0).toString());
   query.finish();
   return res;
}

int DBManager::getAnneeActuelETU(const int id)
{

   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select anneeCourante FROM Dossier where Dossier.ID=?"); // la requete pour avoir le numero du semestre Actuel
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiants
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getAnneeActuelETU"));
       return 0;
   }
   query.first();
   int res;
   res=query.value(0).toInt();
   query.finish();
   return res;
}

bool DBManager::isUVInscrit(const QString& UV, const int& id)
{
    QString ress;
    if (!openDB(db)) //impossible d'ouvrir
    {
        return false;
    }
    QSqlQuery query;
    query.prepare("select Note FROM Inscription where Inscription.NomUv=? and Inscription.IDetu=?"); // la requete pour obtenir le semestre ou elle est enseignée
    query.addBindValue(UV); //permet de remplacer le ? de query.prepare par le nom de l'uv
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isUVInscrit"));
        return false;
    }
    query.first();
    ress=query.value(0).toString();
    enumeration::Note res;
    res=enumeration::StringToNote(ress);
    if(res==enumeration::INSCRIT)
    {
    return true;
    }
    else
    {
        return false;
    }
    query.finish();
}
int DBManager::getSemestreActuelETU(const int id) {
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select NumeroSemestreCourant FROM Dossier where Dossier.ID=?"); // la requete pour avoir le numero du semestre Actuel
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiants
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getSemestreActuelETU"));
       return 0;
   }
   query.first();
   int res;
   res=query.value(0).toInt();
   query.finish();
   return res;

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

bool DBManager::isPCB(const QString &cursus, const QString & uv)
{
    bool res;
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isPCB"));
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT PCB FROM BranchePourUv WHERE BranchePourUv.Nom =? AND BranchePourUv.Uv = ?");
    query.addBindValue(cursus);
    query.addBindValue(uv);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isPCB"));
        return true;
    }
    query.first();
    res = query.value(0).toBool();
    query.finish();
    return res;
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
    QString res;
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
    query.first();
    if (query.isValid()){
        return enumeration::TypeTc;
    }
    query.finish();
    query.prepare("SELECT uv FROM tcPourUV WHERE tcPourUV.nomCursus = ? AND tcPourUV.obligatoire = 1");
    query.addBindValue(nom);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getTypeCursus"));
        return enumeration::ErrorTypeCursus;
    }
    query.first();
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
    query.first();
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
    query.first();
    res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return enumeration::TypeBrancheAvecUvObligatoire;
    }
    qDebug() <<"Arriver à la fin";
    return enumeration::ErrorTypeCursus;
}

bool DBManager::isObligatoireTC(const QString & cursus, const QString & UV){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isObligatoireTC"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("SELECT * FROM TcpourUV WHERE TcpourUV.NomCursus=? AND TcpourUV.UV=? AND TcpourUV.Obligatoire=1;");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(cursus);
    query.addBindValue(UV);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isObligatoireTC"));
        return false;
    }
    QString res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return true;
    }
    return false;
}

bool DBManager::isObligatoireBranche(const QString & cursus, const QString & UV){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isObligatoireBranche"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("SELECT * FROM BranchePourUv WHERE BranchePourUv.Nom=? AND BranchePourUv.UV=? AND BranchePourUv.Obligatoire=1;");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(cursus);
    query.addBindValue(UV);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isObligatoireBranche"));
        return false;
    }
    QString res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return true;
    }
    return false;
}

bool DBManager::isObligatoireMineur(const QString & cursus, const QString & UV){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isObligatoireMineur"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("SELECT * FROM MineurPourUv WHERE MineurPourUv.NomMineur=? AND MineurPourUv.UV=? AND MineurPourUv.Obligatoire=1;");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(cursus);
    query.addBindValue(UV);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isObligatoireMineur"));
        return false;
    }
    QString res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return true;
    }
    return false;
}

bool DBManager::isInList(const QString & cursus, const QString & UV, unsigned int i){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isObligatoireMineur"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("SELECT * FROM MineurPourUv WHERE MineurPourUv.NomMineur=? AND MineurPourUv.UV =? AND MineurPourUv.ListeAppartenance=?");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(cursus);
    query.addBindValue(UV);
    query.addBindValue(i);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isObligatoireMineur"));
        return false;
    }
    QString res = query.value(0).toString();
    query.finish();
    if (!res.isEmpty()){
        return true;
    }
    return false;
}

int DBManager::getNbCreditCSBranche(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditCS FROM Branche where Branche.Nom=?"); // la requete pour obtenir le nombre de credit CS qu'il doit valider dans son cursus actuel de type Branche
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditCSBranche"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditTMBranche(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditTM FROM Branche where Branche.Nom=?"); // la requete pour obtenir le nombre de credit TM qu'il doit valider dans son cursus actuel de type Branche
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditTMBranche"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditTSHBranche(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditTSM FROM Branche where Branche.Nom=?"); // la requete pour obtenir le nombre de credit TSH qu'il doit valider dans son cursus actuel de type Branche
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditTSHBranche"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditLibreBranche(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditLibre FROM Branche where Branche.Nom=?");
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditCursusBranche"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbSemestreBranche(const QString cursus){
    int res;
    if (!openDB(db)) //impossible d'ouvrir
    {
        return 0;
    }
    QSqlQuery query;
    query.prepare("select nbSemestre FROM Branche where Branche.Nom=?");
    query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditCursusBranche"));
        return 0;
    }
    query.first();
    res=query.value(0).toInt();
    query.finish();
    return res;
}

int DBManager::getNbCreditPCB(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditPCB FROM Branche where Branche.Nom=?"); // la requete pour obtenir le nombre de credit PCB qu'il doit valider dans son cursus actuel de type Branche
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditPCB"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditPSF(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select NbCreditPSF FROM Branche where Branche.Nom=?"); // la requete pour obtenir le nombre de credit PSF qu'il doit valider dans son cursus actuel de type Branche
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditPSF"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditCSTC(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("SELECT NbCreditCS FROM TC WHERE TC.Nom = ?"); // la requete pour obtenir le nombre de credit CS qu'il doit valider dans son cursus actuel de type TC
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditCSTC"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditTMTC(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditTM FROM TC where TC.Nom=?"); // la requete pour obtenir le nombre de credit TM qu'il doit valider dans son cursus actuel de type TC
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditTMTC"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditTSHTC(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditTSH FROM TC where TC.Nom=?"); // la requete pour obtenir le nombre de credit TSH qu'il doit valider dans son cursus actuel de type TC
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditTSHTC"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbCreditLibreTC(const QString cursus)
{
   int res;
   if (!openDB(db)) //impossible d'ouvrir
   {
       return 0;
   }
   QSqlQuery query;
   query.prepare("select nbCreditLibre FROM TC where TC.Nom=?");
   query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditCursusTC"));
       return 0;
   }
   query.first();
   res=query.value(0).toInt();
   query.finish();
   return res;
}

int DBManager::getNbSemestreTC(const QString cursus){
    int res;
    if (!openDB(db)) //impossible d'ouvrir
    {
        return 0;
    }
    QSqlQuery query;
    query.prepare("select nbSemestre FROM TC where TC.Nom=?=?");
    query.addBindValue(cursus); //permet de remplacer le ? de query.prepare par le cursus de l'étudiant
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getNbCreditCursusBranche"));
        return 0;
    }
    query.first();
    res=query.value(0).toInt();
    query.finish();
    return res;
}

QStringList & DBManager::getListeUV(const QString & cursus, enumeration::TypeCursus Tcur){
    QStringList * res = new QStringList;
    if (!openDB(db)) //impossible d'ouvrir
    {
        emit sendError(QString("DBManager : Erreur connection à la BDD dans getListeUV"));
        return *res;
    }
    if (Tcur == enumeration::ErrorTypeCursus){
        Tcur = this->getTypeCursus(cursus);
    }
    QSqlQuery query;
    if (Tcur == enumeration::TypeTc || Tcur == enumeration::TypeTcAvecUvObligatoire){
        query.prepare("SELECT uv FROM tcPourUV WHERE tcPourUV.nomCursus = ?");
        query.addBindValue(cursus);
        if(!query.exec()) //pb lors de l'execution
        {
            emit sendError(QString("DBManager : Erreur execution de la requete dans getListeUV"));
            return *res;
        }
        while (query.next())//parcourir toutes les lignes
        {
            qDebug() <<query.value(0).toString();
            res->append(query.value(0).toString());
        }
        query.finish();
        return *res;
    } else if (Tcur == enumeration::TypeBranche || Tcur == enumeration::TypeBrancheAvecUvObligatoire) {
        query.prepare("SELECT uv FROM BranchePourUv WHERE BranchePourUv.nom = ?");
        query.addBindValue(cursus);
        if(!query.exec()) //pb lors de l'execution
        {
            emit sendError(QString("DBManager : Erreur execution de la requete dans getListeUV"));
            return *res;
        }
        while (query.next())//parcourir toutes les lignes
        {
            qDebug() <<query.value(0).toString();
            res->append(query.value(0).toString());
        }
        query.finish();
        return *res;
    }
    emit sendError(QString("DBManager : Terminer à un endroit inapproprié dans getListeUV"));
    return *res;
}

/* Fin Cursus */
/* Debut Choix */

bool DBManager::NewUvREJ(const QString UV,const int id) {
   if (!openDB(db)) //impossible d'ouvrir
   {
       return false;
   }
   QSqlQuery query;
   query.prepare("SELECT Choix FROM Choix where Choix.Uv=? and Choix.IDossier=?");
   query.addBindValue(UV); //permet de remplacer le ? de query.prepare par UV
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par ID du dossier etu
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans NewUvREJ"));
       return false;
   }
   query.first();
   QString res=query.value(0).toString();
   qDebug()<<res;
   query.finish();
   if(!res.isEmpty() && res!="REJ")
   {
       query.prepare("UPDATE Choix SET Choix='REJ' where Choix.UV=? and Choix.IDossier=?"); // la requete pour modifier le choix d'un étudiant
       query.addBindValue(UV); //permet de remplacer le ? de query.prepare par UV
       query.addBindValue(id); //permet de remplacer le ? de query.prepare par ID du dossier etu
       if(!query.exec()) //pb lors de l'execution
       {
           emit sendError(QString("DBManager : Erreur execution de la requete dans NewUvREJ(update)"));
           return false;
       }
   return true;
   query.finish();
   } else {
        query.prepare("INSERT INTO Choix(Cursus,Uv,Choix,IDossier) VALUES (?,?,'REJ',?)"); // la requete pour ajouter le choix d'un étudiant
        //QString cursus=dbm.getCursusEtu(id);
        QString cursus="TEST";
        query.addBindValue(cursus);
        query.addBindValue(UV); //permet de remplacer le ? de query.prepare par UV
        query.addBindValue(id); //permet de remplacer le ? de query.prepare par ID du dossier etu
        if(!query.exec()) //pb lors de l'execution
        {
           emit sendError(QString("DBManager : Erreur execution de la requete dans NewUvREJ(Insert)"));
           return false;
        }
        query.finish();
        return true;
   }
   return false;
}

bool DBManager::NewUvVEUT(const QString UV, const int id) {
   if (!openDB(db)) //impossible d'ouvrir
   {
       return false;
   }
   QSqlQuery query;
   query.prepare("SELECT Choix FROM Choix where Choix.UV=? and Choix.IDossier=?");
   query.addBindValue(UV); //permet de remplacer le ? de query.prepare par UV
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par ID du dossier etu
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans NewUvVEUT"));
       return false;
   }
   query.first();
   QString res=query.value(0).toString();
   qDebug()<<res;

   query.finish();
   if(!res.isEmpty() && res!="VEUT") {
       query.prepare("UPDATE Choix SET Choix='VEUT' where Choix.UV=? and Choix.IDossier=?"); // la requete pour modifier le choix d'un étudiant
       query.addBindValue(UV); //permet de remplacer le ? de query.prepare par UV
       query.addBindValue(id); //permet de remplacer le ? de query.prepare par ID du dossier etu
           if(!query.exec()) //pb lors de l'execution
           {
               emit sendError(QString("DBManager : Erreur execution de la requete dans NewUvVEUT(update)"));
               return false;
           }
       return true;
       query.finish();
   } else if(res!="VEUT") {
        query.prepare("INSERT INTO Choix(Cursus,Uv,Choix,IDossier) VALUES (?,?,'VEUT',?)"); // la requete pour ajouter le choix d'un étudiant
        //QString cursus=dbm.getCursusEtu(id);
        //query.addBindValue(cursus);
        query.addBindValue(UV); //permet de remplacer le ? de query.prepare par UV
        query.addBindValue(id); //permet de remplacer le ? de query.prepare par ID du dossier etu
        if(!query.exec()) //pb lors de l'execution
        {
            emit sendError(QString("DBManager : Erreur execution de la requete dans NewUvVEUT(insert)"));
            return false;
        }
        return true;
        query.finish();
   }
   return false;
}

enumeration::Choix DBManager::getChoix(const QString & nom, const int &id){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getChoix"));
        return enumeration::ErrorChoix;
    }
    QSqlQuery query;
    // la requete
    query.prepare("SELECT Choix FROM Choix WHERE Choix.Uv = ? AND Choix.IDossier =? ");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(id);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getChoix"));
        return enumeration::ErrorChoix;
    }
    query.first();
    if(query.value(0).toString()=="VEUT")
        return enumeration::VEUT;
    else if(query.value(0).toString()=="NEUTRE")
        return enumeration::NEUTRE;
    else if(query.value(0).toString()=="REJ")
        return enumeration::REJ;
    else
        return enumeration::ErrorChoix;
    query.finish();
    return enumeration::ErrorChoix;
}

/* Fin Choix */
/* Debut pour Prevision */

bool DBManager::inscriptionUValide(const int id, const QString UV, const int annee, enumeration::Saison semestre){
   if (!openDB(db)) //impossible d'ouvrir
   {
       emit sendError(QString("DBManager : Erreur lors de la connexion à la Data Base"));
       return false;
   }
   QSqlQuery query;
   query.prepare("INSERT INTO Inscription(IDInscription,NomUv,Note,Annee,Semestre) values ('?','?','INSCRIT','?','?')"); // la requete pour mettre l'uv en INSCRIT
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiant
   query.addBindValue(UV); //permet de remplacer le ? de query.prepare par le nom de l'uv
   query.addBindValue(annee); //permet de remplacer le ? de query.prepare par le nom de l'uv
   query.addBindValue(enumeration::SaisonToString(semestre)); //permet de remplacer le ? de query.prepare par le nom de l'uv
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans inscriptionUValide"));
       return false;
   }
   query.finish();
   return true;
}

bool DBManager::AnnulationPrevision(const int id)
{
   if (!openDB(db)) //impossible d'ouvrir
   {
       return false;
   }
   QSqlQuery query;
   query.prepare("DELETE FROM Inscription where Inscription.id=? and Inscription.Note='INSCRIT'"); // la requete pour enlever toutes les uvs inscrites.
   query.addBindValue(id); //permet de remplacer le ? de query.prepare par l'id de l'étudiant
   if(!query.exec()) //pb lors de l'execution
   {
       emit sendError(QString("DBManager : Erreur execution de la requete dans AnnulationPrevision"));
       return false;
   }
   query.finish();
   return true;
}

/* Fin pour Prevision */
/* Debut Filiere */

bool DBManager::ajouteFiliere (const QString & nom, const QString & descri, const int nbCredit, const QString &cursus){
    if (!openDB(db)) {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour ajouteFiliere"));
        return false;
    }
    QSqlQuery query;
    // la requete
    query.prepare("INSERT INTO Filiere VALUES (?,?,?,?)");
    //permet de remplacer le ? de query.prepare
    query.addBindValue(nom);
    query.addBindValue(descri);
    query.addBindValue(nbCredit);
    query.addBindValue(cursus);
    if(!query.exec()) //pb lors de l'execution
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans ajouteFiliere"));
        return false;
    }
    query.finish();
    return true;
}

QString DBManager::getNomCursusFiliere(const QString &nom)
{
    QString res = QString("");
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getNomCursusFiliere"));
        return res;
    }
    QSqlQuery query;
    query.prepare("SELECT Cursus FROM Filiere WHERE Filiere.Nom =?");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getNomCursusFiliere"));
        return res;
    }
    query.first();
    res = query.value(0).toString();
    query.finish();
    return res;
}


QString DBManager::getDescriptionFiliere(const QString & nom){
    QString res = QString("");
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour getDescriptionFiliere"));
        return res;
    }
    QSqlQuery query;
    query.prepare("SELECT description FROM Filiere WHERE Filiere.Nom =?");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans getDescriptionFiliere"));
        return res;
    }
    query.first();
    res = query.value(0).toString();
    query.finish();
    return res;
}

bool DBManager::isFiliere(const QString &nom)
{
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isFiliere"));
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT Nom FROM Filiere WHERE Filiere.Nom =?");
    query.addBindValue(nom);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isFiliere"));
        return false;
    }
    query.first();
    QString res;
    res = query.value(0).toString();
    if(!res.isEmpty())
    {
        return true; // Si la filiere existe bien dans la bdd on renvoit true.
    }
    query.finish();
    return false;
}

bool DBManager::isUVFiliere(const QString &nom, const QString &UV)
{
    if (!openDB(db)) //impossible d'ouvrir la BDD
    {
        emit sendError(QString("DBManager : la BDD n est pas ouverte pour isUVFiliere"));
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT Nom FROM Filiere WHERE FilierePourUv.NomFiliere =? and FilierePourUv.Uv=?");
    query.addBindValue(nom);
    query.addBindValue(UV);
    if(!query.exec())
    {
        emit sendError(QString("DBManager : Erreur execution de la requete dans isUVFiliere"));
        return false;
    }
    query.first();
    QString res;
    res = query.value(0).toString();
    if(!res.isEmpty())
    {
        return true; // Si l'uv est bien une UV de cette filiere, on renvoit true.
    }
    query.finish();
    return false;
}

/* Fin Filiere */
