#include "dialogAjouterCursusTC.h"
#include "ui_dialogAjouterCursusTC.h"

dialogAjouterCursusTC::dialogAjouterCursusTC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterCursusTC)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutTC()));
}

dialogAjouterCursusTC::~dialogAjouterCursusTC()
{
    delete ui;
}

void dialogAjouterCursusTC::ajoutTC(){
    DBManager & dbm = DBManager::getInstance();
    dbm.ajouteTC(ui->nomTC->text(),ui->descriTC->toPlainText(),ui->csTC->value(),ui->tmTC->value(),ui->tshTC->value(),ui->libreTC->value(),ui->dureeTC->value());
}
