#include "dialogAjouterFiliere.h"
#include "ui_dialogAjouterFiliere.h"

dialogAjouterFiliere::dialogAjouterFiliere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterFiliere)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox_2, SIGNAL(accepted()), this, SLOT(ajouteFiliere()));
    DBManager & dbm = DBManager::getInstance();
    QStringList & q=dbm.rechercheNomCursusBranche();
    for (int i = 0; i < q.size(); ++i){
        ui->brFIl->addItem(QString(q[i]));
    }
}

dialogAjouterFiliere::~dialogAjouterFiliere()
{
    delete ui;
}

void dialogAjouterFiliere::ajouteFiliere(){
    DBManager & dbm = DBManager::getInstance();
    dbm.ajouteFiliere(ui->nomFil->text(),ui->descriFil->toPlainText(),ui->brFIl->currentText());
}
