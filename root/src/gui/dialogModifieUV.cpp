#include "dialogModifieUV.h"
#include "ui_dialogModifieUV.h"

dialogModifieUV::dialogModifieUV(const QString & n,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogModifieUV)
{
    DBManager & dbm = DBManager::getInstance();
    ui->setupUi(this);
    ui->nomUV->setText(n);
    ui->descriUV->setText(dbm.getDescriptionUV(n));
    ui->nbCreditsUV->setValue(dbm.getCreditsUV(n));
    for (int i = enumeration::CS; i != enumeration::ErrorCategorieUV;i++){
        ui->catUV->addItem(enumeration::CategorieUVToString(static_cast<enumeration::CategorieUV>(i)));
    }
    for (int i = enumeration::Automne; i != enumeration::ErrorSaison;i++){
        ui->semestreUV->addItem(enumeration::SaisonToString(static_cast<enumeration::Saison>(i)));
    }
    QObject::connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(aEteAccepte()));
}

dialogModifieUV::~dialogModifieUV()
{
    delete ui;
}

void dialogModifieUV::aEteAccepte(){
    DBManager & dbm = DBManager::getInstance();
    qDebug() <<ui->descriUV->toPlainText();
    qDebug() <<ui->nomUV->text();
    qDebug() <<ui->semestreUV->currentText();
    qDebug() <<ui->catUV->currentText();
    qDebug() <<ui->nbCreditsUV->value();
    dbm.modifieUV(ui->nomUV->text(),ui->descriUV->toPlainText(),enumeration::StringToSaison(ui->semestreUV->currentText()),enumeration::StringToCategorieUV(ui->catUV->currentText()),ui->nbCreditsUV->value());
}
