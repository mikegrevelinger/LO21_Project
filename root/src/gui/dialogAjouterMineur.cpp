#include "dialogAjouterMineur.h"
#include "ui_dialogAjouterMineur.h"

dialogAjouterMineur::dialogAjouterMineur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterMineur)
{
    ui->setupUi(this);
}

dialogAjouterMineur::~dialogAjouterMineur()
{
    delete ui;
}
