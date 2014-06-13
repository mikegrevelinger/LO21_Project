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
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutEtudiant()));
}

dialogAjouterUV::~dialogAjouterUV()
{
    delete ui;
}

void dialogAjouterUV::ajoutEtudiant(){

}
