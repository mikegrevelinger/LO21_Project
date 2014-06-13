#include "dialogAjouterUV.h"
#include "ui_dialogAjouterUV.h"

dialogAjouterUV::dialogAjouterUV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterUV)
{
    ui->setupUi(this);
    ui->comboBoxCat->addItem(QString("lol"));
    ui->comboBoxSemestre->addItem(QString("lol"));
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutEtudiant()));
}

dialogAjouterUV::~dialogAjouterUV()
{
    delete ui;
}

void dialogAjouterUV::ajoutEtudiant(){

}
