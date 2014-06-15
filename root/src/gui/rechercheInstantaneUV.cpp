#include "rechercheInstantaneUV.h"

rechercheInstantaneUV::rechercheInstantaneUV(QWidget * parent) :
    QWidget(parent),regexRechercheUV("^[a-zA-Z0-9]{1,4}")
{
    l = new QLineEdit(this);
    layout = new QGridLayout(this);

    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","resources/");

    ajoutUVPixmap = new QPixmap(QString("%1iconAjout.png").arg(CurrentDir));
    ajoutUV = new ClickableQLabel(this);
    ajoutUV->setPixmap(*ajoutUVPixmap);
    ajoutUV->setFixedSize(QSize(32,32));

    table = new QTableWidget(this);
    table->setColumnCount(4);
    table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table->setMinimumSize(550,150);
    headerText<<"Nom"<<"Categorie"<<"Credits"<<"Description";//titre des colonnes
    table->setHorizontalHeaderLabels(headerText);
    header = new QHeaderView(Qt::Horizontal, table);
    //header->setSectionResizeMode(QHeaderView::Stretch); SI on veut toutes les colonnes de taille égale + prennent toutes la place possible
    header->setStretchLastSection(true);//Dernier colonne prendra la place qu'il reste
    table->setHorizontalHeader(header);
    table->verticalHeader()->setVisible(false);//pas de titre pour les lignes
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //Pour interdire la modification des cellules
    table->setSelectionBehavior(QAbstractItemView::SelectRows);//Utilisateur selectionne des lignes
    table->setSelectionMode(QAbstractItemView::SingleSelection);//utilisateur selectionne une unique ligne à la fois
    table->setShowGrid(false);
    table->setStyleSheet("QTableView {selection-background-color: red;}");
    table->setGeometry(QApplication::desktop()->screenGeometry());

    //table->setItem(0,0,new QTableWidgetItem("Nom"));

    layout->addWidget(l,0,0);
    layout->addWidget(ajoutUV,0,1);
    layout->addWidget(table,3,0,1,2);
    setLayout(layout);

    QObject::connect(l, SIGNAL(textChanged(QString)), this, SLOT(slotRechercherUV(QString)));
    QObject::connect(table, SIGNAL(cellDoubleClicked(int , int)), this, SLOT(ouvrirDialogModifieUV(int , int)));
    QObject::connect(ajoutUV, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterUV()));
}

rechercheInstantaneUV::~rechercheInstantaneUV(){
    delete ajoutUVPixmap;
    delete ajoutUV;
    table->setRowCount(0);
    delete table;
    delete l;
    delete table;
    delete header;
    delete layout;
}

void rechercheInstantaneUV::slotRechercherUV(QString p){
    if ((!p.isNull()) && regexRechercheUV.exactMatch(p)){
        DBManager & dbm = DBManager::getInstance();
        QList<QStringList > q = dbm.rechercheUV(p);
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
    else if(p.size()>4){
        qDebug() <<"Trop long";
        table->setRowCount(0);
    }
    else {
        qDebug() <<"Erreur dans la saisie";
        table->setRowCount(0);
    }
}


void rechercheInstantaneUV::ouvrirDialogModifieUV(int nRow, int nCol)
{
    dialogModifieUV * dUV = new dialogModifieUV(table->item(nRow,0)->text());
    dUV->exec();
}

void rechercheInstantaneUV::ouvrirDialogAjouterUV() {
    dialogAjouterUV * dUV = new dialogAjouterUV;
    dUV->exec();
}
