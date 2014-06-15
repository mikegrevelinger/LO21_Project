#include "rechercheInstantaneCursus.h"

rechercheInstantaneCursus::rechercheInstantaneCursus(QWidget * parent) :
    QWidget(parent),regexRechercheCursus("^[a-zA-Z]{1,20}")
{
    l = new QLineEdit(this);
    layout = new QGridLayout(this);

    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","resources/");

    ajoutPixmap = new QPixmap(QString("%1iconAjout.png").arg(CurrentDir));
    ajout = new ClickableQLabel(this);
    ajout->setPixmap(*ajoutPixmap);
    ajout->setFixedSize(QSize(32,32));

    table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table->setMinimumSize(550,150);
    headerText<<"Nom"<<"Description"<<"Type";//titre des colonnes
    table->setHorizontalHeaderLabels(headerText);
    header = new QHeaderView(Qt::Horizontal, table);
    header->setSectionResizeMode(QHeaderView::Stretch);
    table->setHorizontalHeader(header);
    table->verticalHeader()->setVisible(false);//pas de titre pour les lignes
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //Pour interdire la modification des cellules
    table->setSelectionBehavior(QAbstractItemView::SelectRows);//Utilisateur selectionne des lignes
    table->setSelectionMode(QAbstractItemView::SingleSelection);//utilisateur selectionne une unique ligne à la fois
    table->setShowGrid(false);
    table->setStyleSheet("QTableView {selection-background-color: red;}");
    table->setGeometry(QApplication::desktop()->screenGeometry());

    ap = new ClickableQLabel(this);
    ap->setText("CLiquer pour ajouter UV à un TC");

    layout->addWidget(l,0,0);
    layout->addWidget(ajout,0,1);
    layout->addWidget(table,1,0,1,2);
    layout->addWidget(ap,2,0,1,2);
    setLayout(layout);

    QObject::connect(l, SIGNAL(textChanged(QString)), this, SLOT(slotRechercherCursus(QString)));
    //QObject::connect(table, SIGNAL(cellDoubleClicked(int , int)), this, SLOT(ouvrirDialogModifieCursus(int , int)));
    QObject::connect(ajout, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterCursus()));
    QObject::connect(ap, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterUVTC()));
}

rechercheInstantaneCursus::~rechercheInstantaneCursus(){
    delete ajoutPixmap;
    delete ajout;
    table->setRowCount(0);
    delete table;
    delete l;
    delete table;
    delete header;
    delete layout;
}

void rechercheInstantaneCursus::slotRechercherCursus(QString p){
    if ((!p.isNull()) && regexRechercheCursus.exactMatch(p)){
        DBManager & dbm = DBManager::getInstance();
        QList<QStringList > q = dbm.rechercheCursus(p);
        table->setRowCount(q.size());
        for(int i = 0 ;i<q.size();i++){
            for(int j = 0;j<q[i].size();j++){
                table->setItem(i,j,new QTableWidgetItem(q[i].at(j)));
            }
        }
        table->resizeRowsToContents();
        table->sortItems(1);
        for (int i = 0; i < q.size(); ++i) {
             q[i].clear();
        }
        q.clear();
    }
    else if(p.isEmpty()){
        qDebug() <<"Vide";
        table->setRowCount(0);//Supprime egalement de la mémoire les QTableWidgetItem. COOL !
    }
    else if(p.size()>20){
        qDebug() <<"Trop long";
        table->setRowCount(0);
    }
    else {
        qDebug() <<"Erreur dans la saisie";
        table->setRowCount(0);
    }
}


void rechercheInstantaneCursus::ouvrirDialogAjouterCursus() {
    dialogAjouterCursus * d = new dialogAjouterCursus(this);
    d->exec();
}

void rechercheInstantaneCursus::ouvrirDialogAjouterCursusBLA(QString a){
    if (a == "Branche"){
        dialogAjouterCursusBranche * d = new dialogAjouterCursusBranche;
        d->exec();
    } else if (a == "Filiere") {
        dialogAjouterFiliere * d = new dialogAjouterFiliere;
        d->exec();
    } else if (a == "Mineur") {
        dialogAjouterMineur * d = new dialogAjouterMineur;
        d->exec();
    } else if (a == "TC"){
        dialogAjouterCursusTC * d = new dialogAjouterCursusTC;
        d->exec();
    }
}

void rechercheInstantaneCursus::ouvrirDialogAjouterUVTC(){
    dialogAjouterUVTC * d = new dialogAjouterUVTC(this);
    d->exec();
}
