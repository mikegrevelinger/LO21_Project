#include "UVManager.h"


/* Debut partie SINGLETON */
HandlerSingleton<UVManager> UVManager::handler = HandlerSingleton<UVManager> ();

UVManager & UVManager::getInstance(){
    if (!handler.instance)
        handler.instance = new UVManager;
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance){
        delete handler.instance;
        handler.instance = 0;
    }
}
/* Fin partie SINGLETON */



UVManager::~UVManager(){
}

void UVManager::ajouterUV(const QString& nom, Categorie cat, unsigned int nbc,const QString& description){
    if (UVManager::rechercheUV(nom)) {
        emit sendError(QString("Deja existante"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.ajouterUV(nom,cat,nbc,description);
    }
}

void UVManager::modifierUV(const QString& nom, Categorie cat=0, unsigned int nbc=0,const QString& description=0){
    if (!rechercheUV(nom)) {
        emit sendError(QString("existe pas"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.modifierUV(nom,cat,nbc,description);
    }
}


QVector<QVector<QString> > UVManager::rechercherUV(const QString& name)const{
    DBManager & dbm = DBManager::getInstance();
    dbm.rechercheUV(name);
}

QVector<QVector<QString> > UVManager::rechercherUV(Categorie cat)const{
    DBManager & dbm = DBManager::getInstance();
    dbm.rechercheUV(Categorie cat);
}

void UVManager::supprimerUV(const QString& nom){
    if (!UVManager::rechercheUV(nom)) {
        emit sendError(QString("existe pas"));
    }else{
       DBManager & dbm = DBManager::getInstance();
       dbm.supprimerUV(nom);
    }
}


UVManager::UVManager() {
    //Connect pour envoyer des signaux d'erreurs
    QObject::connect(this, SIGNAL(sendError(QString)), &ErrorManager::getInstance(), SLOT(mailBoxError(QString)));
    /* FAUX
    if (!db.isValid())
    {
        qDebug() << "Impossible de se connecter a la base de donnees";
        emit sendError(QString("Impossible de se connecter a la base de donnees"));
    }
    */
}

/*
#include <sstream>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>



UVManager::UVManager():uvs(0),nbUV(0),nbMaxUV(0),file(""),modification(false){
}


// construction fichier... à enlever
bool isInFile(QString code, QString file){
    QFile fin(file);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier ")+file);
    QTextStream flux(&fin);
     while (!flux.atEnd()){
        QString codeuv=flux.readLine();
        if (code==codeuv) return true;
    }
    fin.close();
    return false;
}

void UVManager::load(const QString& f){
    if (file!=f) this->~UVManager();
    file=f;

    //QFile fin(file);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier ")+file);
    QTextStream flux(&fin);
    //QTextCodec *codec = QTextCodec::codecForName("Windows-1252");
    //flux.setCodec(codec);
    while (!flux.atEnd()){
        QString code=flux.readLine();
        QString titre=flux.readLine();
        QString tmp=flux.readLine();
        unsigned int nbCredits=tmp.toUInt();
        QString tmpcat=flux.readLine();
        Categorie cat=StringToCategorie(tmpcat);
        ajouterUV(code,titre,nbCredits,cat);
    }
    fin.close(); // close file


    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw UTProfilerException("Erreur ouverture fichier UV");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named uvs, we'll go to the next.
            if(xml.name() == "uvs") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "uv") {
                QString code;
                QString titre;
                unsigned int nbCredits;
                Categorie cat;
                bool automne=false;
                bool printemps=false;

                QXmlStreamAttributes attributes = xml.attributes();
                // Let's check that uvs has attribute.
                if(attributes.hasAttribute("automne")) {
                    QString val =attributes.value("automne").toString();
                    automne=(val == "true" ? true : false);
                }
                if(attributes.hasAttribute("printemps")) {
                    QString val =attributes.value("printemps").toString();
                    printemps=(val == "true" ? true : false);
                }

                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named uv.


                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "uv")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        if(xml.name() == "code") {
                            xml.readNext(); code=xml.text().toString();
                        }
                        // We've found titre.
                        if(xml.name() == "titre") {
                            xml.readNext(); titre=xml.text().toString();
                        }
                        // We've found credits.
                        if(xml.name() == "credits") {
                            xml.readNext(); nbCredits=xml.text().toString().toUInt();
                        }
                        // We've found categorie
                        if(xml.name() == "categorie") {
                            xml.readNext(); cat=StringToCategorie(xml.text().toString());
                        }
                    }
                    // ...and next...
                    xml.readNext();
                }

                // construction fichier : à enlever
                //if (isInFile(code,"../Ressources/automne.txt")) automne=true;
                //if (isInFile(code,"../Ressources/printemps.txt")) printemps=true;

                ajouterUV(code,titre,nbCredits,cat,automne,printemps);

            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier UV, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}



void UVManager::save(const QString& f){

    QMessageBox msgBox;
     msgBox.setText("Debut The document has been saved.");
     msgBox.exec();

    file=f;
    // QFile fichier(file); // toutes les UVs existantes sont écrasées
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier ")+file);

    QTextStream fout(&fichier);
    for(unsigned int i=0; i<nbUV; i++){
        fout<<uvs[i]->getCode()<<"\n";
        fout<<uvs[i]->getTitre()<<"\n";
        fout<<uvs[i]->getNbCredits()<<"\n";
        fout<<uvs[i]->getCategorie()<<"\n";
    }
    fichier.close();*/

/*   QDomDocument doc( "UV_XML" );
    QDomElement root = doc.createElement( "uvs" );
    doc.appendChild( root );
    for(unsigned int i=0; i<nbUV; i++){
        QDomElement uv = doc.createElement("uv");
        uv.setNodeValue(uvs[i]->getCode());
        QDomElement code = doc.createElement( "code" ); code.setNodeValue(uvs[i]->getCode()); uv.appendChild(code);
        QDomElement titre = doc.createElement( "titre" ); titre.setNodeValue(uvs[i]->getTitre()); uv.appendChild(titre);
        root.appendChild(uv);
    }

    QFile file( "Z:/test.xml" );
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier xml"));

     QTextStream ts( &file );
     ts << doc.toString();
     file.close();*/
/*
    QFile newfile( file);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier xml"));
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("uvs");
     for(unsigned int i=0; i<nbUV; i++){
         stream.writeStartElement("uv");
         stream.writeAttribute("automne", (uvs[i]->ouvertureAutomne())?"true":"false");
         stream.writeAttribute("printemps", (uvs[i]->ouverturePrintemps())?"true":"false");
         stream.writeTextElement("code",uvs[i]->getCode());
         stream.writeTextElement("titre",uvs[i]->getTitre());
         QString cr; cr.setNum(uvs[i]->getNbCredits());
         stream.writeTextElement("credits",cr);
         stream.writeTextElement("categorie",CategorieToString(uvs[i]->getCategorie()));
         stream.writeEndElement();
     }
     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();

}

UVManager::~UVManager(){
    if (file!="") save(file);
    for(unsigned int i=0; i<nbUV; i++) delete uvs[i];
    delete[] uvs;
}

void UVManager::addItem(UV* uv){
    if (nbUV==nbMaxUV){
        UV** newtab=new UV*[nbMaxUV+10];
        for(unsigned int i=0; i<nbUV; i++) newtab[i]=uvs[i];
        nbMaxUV+=10;
        UV** old=uvs;
        uvs=newtab;
        delete[] old;
    }
    uvs[nbUV++]=uv;
}

void UVManager::ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p){
    if (trouverUV(c)) {
        throw UTProfilerException(QString("erreur, UVManager, UV ")+c+QString("déja existante"));
    }else{
        UV* newuv=new UV(c,t,nbc,cat,a,p);
        addItem(newuv);
        modification=true;
    }
}

UV* UVManager::trouverUV(const QString& c)const{
    for(unsigned int i=0; i<nbUV; i++)
        if (c==uvs[i]->getCode()) return uvs[i];
    return 0;
}

UV& UVManager::getUV(const QString& code){
    UV* uv=trouverUV(code);
    if (!uv) throw UTProfilerException("erreur, UVManager, UV inexistante");
    return *uv;
}


const UV& UVManager::getUV(const QString& code)const{
    return const_cast<UVManager*>(this)->getUV(code);
        // on peut aussi dupliquer le code de la méthode non-const
}

UVManager::Handler UVManager::handler=Handler();

UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager; // instance créée une seule fois lors de la première utilisation
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}

*/
