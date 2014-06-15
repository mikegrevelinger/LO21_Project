#include "rechercheInstantaneDossier.h"

rechercheInstantaneDossier::rechercheInstantaneDossier(QWidget * parent) :
    QWidget(parent),regexRechercheDossier("^[a-zA-Z]{1,20}")
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
    table->setColumnCount(4);
    table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table->setMinimumSize(550,150);
    headerText<<"Nom"<<"Categorie"<<"Credits"<<"Description";//titre des colonnes
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

    layout->addWidget(l,0,0);
    layout->addWidget(ajout,0,1);
    layout->addWidget(table,3,0,1,2);
    setLayout(layout);

    QObject::connect(l, SIGNAL(textChanged(QString)), this, SLOT(slotRechercherDossier(QString)));
    //QObject::connect(table, SIGNAL(cellDoubleClicked(int , int)), this, SLOT(ouvrirDialogModifieDossier(int , int)));
    QObject::connect(ajout, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterDossier()));
}

rechercheInstantaneDossier::~rechercheInstantaneDossier(){
    delete ajoutPixmap;
    delete ajout;
    table->setRowCount(0);
    delete table;
    delete l;
    delete table;
    delete header;
    delete layout;
}

void rechercheInstantaneDossier::slotRechercherDossier(QString p){
    if ((!p.isNull()) && regexRechercheDossier.exactMatch(p)){
        DBManager & dbm = DBManager::getInstance();
        QList<QStringList > q = dbm.rechercheETU(p);
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
        table->setRowCount(0);
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

/*
void rechercheInstantaneDossier::ouvrirDialogModifieDossier(int nRow, int nCol)
{
    dialogModifieDossier * d = new dialogModifieDossier(table->item(nRow,0)->text());
    d->exec();
}
*/

void rechercheInstantaneDossier::ouvrirDialogAjouterDossier() {
    dialogAjouterDossier * d = new dialogAjouterDossier;
    d->exec();
}
