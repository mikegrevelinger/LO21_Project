#include "dialogAjouterFiliere.h"
#include "ui_dialogAjouterFiliere.h"

dialogAjouterFiliere::dialogAjouterFiliere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterFiliere)
{
    ui->setupUi(this);
}

dialogAjouterFiliere::~dialogAjouterFiliere()
{
    delete ui;
}
