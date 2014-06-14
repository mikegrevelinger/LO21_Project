#include "rechercheInstantaneDossier.h"

rechercheInstantaneDossier::rechercheInstantaneDossier(QWidget * parent) :
    QWidget(parent),regexRechercheDossier("^[a-zA-Z]{1,20}")
{
    l = new QLineEdit(this);
    layout = new QGridLayout(this);
    label = new QLabel(this);
    label->setText("Double cliquer sur la ligne pour modifier le Dossier");
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
    table->setColumnCount(6);
    table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table->setMinimumSize(550,150);
    headerText<<"ID"<<"Nom étudiant"<<"Prenom étudiant"<<"Civilite"<<"Nationalite"<<"Date de Naissance";
    table->setHorizontalHeaderLabels(headerText);
    header = new QHeaderView(Qt::Horizontal, table);
    header->setSectionResizeMode(QHeaderView::Stretch);
    table->setHorizontalHeader(header);
    table->verticalHeader()->setVisible(false);//pas de titre pour les lignes
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //Pour interdire la modification des cellules
    table->setSelectionBehavior(QAbstractItemView::SelectRows);//Utilisateur selectionne des lignes
    table->setSelectionMode(QAbstractItemView::SingleSelection);//utilisateur selectionne une unique ligne à la fois
    table->setShowGrid(false);
    table->setStyleSheet("QTableView {selection-background-color: blue;}");
    table->setGeometry(QApplication::desktop()->screenGeometry());

    //table->setItem(0,0,new QTableWidgetItem("Nom"));

    layout->addWidget(search,0,0,3,1);
    layout->addWidget(l,0,1);
    layout->addWidget(ajoutUV,0,2,3,1);
    layout->addWidget(label,1,1);
    layout->addWidget(message,2,1);
    layout->addWidget(table,3,0,1,3);
    setLayout(layout);

    QObject::connect(l, SIGNAL(textChanged(QString)), this, SLOT(slotRechercherDossier(QString)));
    QObject::connect(table, SIGNAL(cellDoubleClicked(int , int)), this, SLOT(cellSelected(int , int)));
    QObject::connect(ajoutUV, SIGNAL(clicked()), this, SLOT(ouvrirDialogAjouterDossier()));
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


void rechercheInstantaneDossier::cellSelected(int nRow, int nCol)
{
    QMessageBox::information(this, "","Cell at row "+QString::number(nRow)+" column "+QString::number(nCol)+" was double clicked.Text :"+table->item(nRow,0)->text()+" !");
}

void rechercheInstantaneDossier::ouvrirDialogAjouterDossier() {
    dialogAjouterDossier * dUV = new dialogAjouterDossier;
    dUV->exec();
}
