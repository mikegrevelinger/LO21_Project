#include "dialogAjouterDossier.h"
#include "ui_dialogAjouterDossier.h"

dialogAjouterDossier::dialogAjouterDossier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterDossier)
{
    ui->setupUi(this);
}

dialogAjouterDossier::~dialogAjouterDossier()
{
    delete ui;
}
