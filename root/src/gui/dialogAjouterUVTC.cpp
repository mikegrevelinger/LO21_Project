#include "dialogAjouterUVTC.h"
#include "ui_dialogAjouterUVTC.h"

dialogAjouterUVTC::dialogAjouterUVTC(QWidget *parent) : QDialog(parent), ui(new Ui::dialogAjouterUVTC)
{
    ui->setupUi(this);
    DBManager & dbm = DBManager::getInstance();
    QStringList & p = dbm.rechercheNomCursusTC();
    for (int i = 0; i < p.size(); ++i){
        ui->uvNomTC->addItem(QString(p[i]));
    }
    p = dbm.rechercheNomUV();
    for (int i = 0; i < p.size(); ++i){
        ui->cursusNomTC->addItem(QString(p[i]));
    }
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajouteUVTC()));
}

dialogAjouterUVTC::~dialogAjouterUVTC()
{
    delete ui;
}

void dialogAjouterUVTC::ajouteUVTC(){
    DBManager & dbm = DBManager::getInstance();
    bool p;
    if (ui->radioButton->isChecked()){
        p = true;
    } else {
        p = false;
    }
    dbm.ajouteTCPourUV(ui->uvNomTC->currentText(),ui->cursusNomTC->currentText(),p);
}
