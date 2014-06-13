#include "rechercheInstantaneUV.h"

rechercheInstantaneUV::rechercheInstantaneUV(QWidget *parent) :
    QWidget(parent),regexRechercheUV("^[a-zA-Z0-9]{1,4}")
{
    l = new QLineEdit(this);
    layout = new QGridLayout(this);
    label = new QLabel(this);
    label->setText("Double cliquer sur la ligne pour modifier l'UV");
    message = new QLabel(this);
    searchPixmap = new QPixmap(QString("iconSearch.png"));
    search = new QLabel(this);
    search->setPixmap(*searchPixmap);
    search->setFixedSize(QSize(32,32));

    ajoutUVPixmap = new QPixmap(QString("iconAjout.png"));
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

    table->setItem(0,0,new QTableWidgetItem("Nom"));

    layout->addWidget(search,0,0,3,1);
    layout->addWidget(l,0,1);
    layout->addWidget(ajoutUV,0,2,3,1);
    layout->addWidget(label,1,1);
    layout->addWidget(message,2,1);
    layout->addWidget(table,3,0,1,3);
    setLayout(layout);

    QObject::connect(l, SIGNAL(textChanged(QString)), this, SLOT(slotRechercherUV(QString)));
    QObject::connect(table, SIGNAL(cellDoubleClicked(int , int)), this, SLOT(cellSelected(int , int)));
    QObject::connect(ajoutUV, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterUV()));
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
        q.clear();
        message->clear();
    }
    else if(p.isEmpty()){
        qDebug() <<"Vide";
        table->setRowCount(0);
        message->setText(QString("Vide"));
    }
    else if(p.size()>4){
        qDebug() <<"Trop long";
        table->setRowCount(0);
        message->setText(QString("Trop long. Il faut entrer au maximum 4 caractères."));
    }
    else {
        qDebug() <<"Erreur dans la saisie";
        table->setRowCount(0);
        message->setText(QString("Erreur dans la saisie."));
    }
}


void rechercheInstantaneUV::cellSelected(int nRow, int nCol)
{
    QMessageBox::information(this, "","Cell at row "+QString::number(nRow)+" column "+QString::number(nCol)+" was double clicked.");
}

void rechercheInstantaneUV::ouvrirDialogAjouterUV() {
    dialogAjouterUV * dUV = new dialogAjouterUV;
    dUV->exec();
}
