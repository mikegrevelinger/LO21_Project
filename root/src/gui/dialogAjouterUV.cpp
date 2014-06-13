#include "dialogAjouterUV.h"
#include "ui_dialogAjouterUV.h"

dialogAjouterUV::dialogAjouterUV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterUV)
{
    ui->setupUi(this);
}

dialogAjouterUV::~dialogAjouterUV()
{
    delete ui;
}
