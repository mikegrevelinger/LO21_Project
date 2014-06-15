#include "rechercheInstantaneCursus.h"

rechercheInstantaneCursus::rechercheInstantaneCursus(QWidget * parent) :
    QWidget(parent),regexRechercheCursus("^[a-zA-Z]{1,20}")
{
    l = new QLineEdit(this);
    layout = new QGridLayout(this);
    messageDouble = new QString("Double cliquer sur la ligne pour modifier le Cursus");
    label = new QLabel(this);
    label->setText(*messageDouble);
    message = new QLabel(this);

    QString CurrentDir = QDir::currentPath();
    CurrentDir.replace("build-Project_LO21-Desktop_Qt_5_3_0_MinGW_32bit-Debug","resources/");

    searchPixmap = new QPixmap(QString("%1iconSearch.png").arg(CurrentDir));
    search = new QLabel(this);
    search->setPixmap(*searchPixmap);
    search->setFixedSize(QSize(32,32));

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

    layout->addWidget(search,0,0,3,1);
    layout->addWidget(l,0,1);
    layout->addWidget(ajout,0,2,3,1);
    layout->addWidget(label,1,1);
    layout->addWidget(message,2,1);
    layout->addWidget(table,3,0,1,3);
    setLayout(layout);

    QObject::connect(l, SIGNAL(textChanged(QString)), this, SLOT(slotRechercherCursus(QString)));
    QObject::connect(table, SIGNAL(cellDoubleClicked(int , int)), this, SLOT(ouvrirDialogModifieCursus(int , int)));
    QObject::connect(ajout, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterCursus()));
}

rechercheInstantaneCursus::~rechercheInstantaneCursus(){
    label->setText("");
    delete messageDouble;
    delete searchPixmap;
    delete search;
    delete ajoutPixmap;
    delete ajout;
    table->setRowCount(0);
    delete table;
    delete l;
    delete label;
    delete table;
    delete header;
    delete message;
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
        message->clear();
    }
    else if(p.isEmpty()){
        qDebug() <<"Vide";
        table->setRowCount(0);//Supprime egalement de la mémoire les QTableWidgetItem. COOL !
        message->setText(QString("Vide"));
    }
    else if(p.size()>20){
        qDebug() <<"Trop long";
        table->setRowCount(0);
        message->setText(QString("Trop long. Il faut entrer au maximum 20 caractères."));
    }
    else {
        qDebug() <<"Erreur dans la saisie";
        table->setRowCount(0);
        message->setText(QString("Erreur dans la saisie."));
    }
}


void rechercheInstantaneCursus::ouvrirDialogAjouterCursus() {
    dialogAjouterCursus * d = new dialogAjouterCursus;
    d->exec();
}
