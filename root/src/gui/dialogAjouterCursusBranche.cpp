#include "dialogAjouterCursusBranche.h"
#include "ui_dialogAjouterCursusBranche.h"

dialogAjouterCursusBranche::dialogAjouterCursusBranche(QWidget *parent) : QDialog(parent), ui(new Ui::dialogAjouterCursusBranche) {
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutBranche()));
}

dialogAjouterCursusBranche::~dialogAjouterCursusBranche()
{
    delete ui;
}

void dialogAjouterCursusBranche::ajoutBranche(){
    DBManager & dbm = DBManager::getInstance();
    dbm.ajouteBranche(ui->nomBr->text(),ui->descriBr->toPlainText(),ui->csBR->value(),ui->tmBR->value(),ui->tshBR->value(),ui->libreBR->value(),ui->pcbBR->value(),ui->filBR->value(),ui->dureeBr->value());
}
