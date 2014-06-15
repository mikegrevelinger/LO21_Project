#include "dialogAjouterUV.h"
#include "ui_dialogAjouterUV.h"

dialogAjouterUV::dialogAjouterUV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterUV)
{
    ui->setupUi(this);
    for (int i = enumeration::CS; i != enumeration::ErrorCategorieUV;i++){
        ui->comboBoxCat->addItem(enumeration::CategorieUVToString(static_cast<enumeration::CategorieUV>(i)));
    }
    for (int i = enumeration::Automne; i != enumeration::ErrorSaison;i++){
        ui->comboBoxSemestre->addItem(enumeration::SaisonToString(static_cast<enumeration::Saison>(i)));
    }
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutUV()));
}

dialogAjouterUV::~dialogAjouterUV()
{
    delete ui;
}

void dialogAjouterUV::ajoutUV(){
    DBManager & dbm = DBManager::getInstance();
    qDebug() <<ui->textEditDescription->toPlainText();
    qDebug() <<ui->lineEditNom->text();
    qDebug() <<ui->comboBoxSemestre->currentText();
    qDebug() <<ui->comboBoxCat->currentText();
    qDebug() <<ui->choixCredit->value();
    dbm.ajouteUV(ui->lineEditNom->text(),enumeration::StringToCategorieUV(ui->comboBoxCat->currentText()),enumeration::StringToSaison(ui->comboBoxSemestre->currentText()),ui->choixCredit->value(),ui->textEditDescription->toPlainText());
}
