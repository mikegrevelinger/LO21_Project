#include "dialogAjouterCursusBranche.h"
#include "ui_dialogAjouterCursusBranche.h"

dialogAjouterCursusBranche::dialogAjouterCursusBranche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterCursusBranche)
{
    ui->setupUi(this);
}

dialogAjouterCursusBranche::~dialogAjouterCursusBranche()
{
    delete ui;
}
