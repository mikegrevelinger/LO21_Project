#include "dialogAjouterCursus.h"
#include "ui_dialogAjouterCursus.h"

dialogAjouterCursus::dialogAjouterCursus(rechercheInstantaneCursus * p,QWidget *parent) : QDialog(parent), ui(new Ui::dialogAjouterCursus) {
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutDossier()));
    QObject::connect(this, SIGNAL(selectionCreationCursus(QString)), p, SLOT(ouvrirDialogAjouterCursusBLA(QString)));
}

dialogAjouterCursus::~dialogAjouterCursus()
{
    delete ui;
}

void dialogAjouterCursus::ajoutDossier(){
    if (ui->checkBranche->isChecked()){
        emit selectionCreationCursus(QString("Branche"));
    } else if (ui->checkFiliere->isChecked()){
        emit selectionCreationCursus(QString("Filiere"));
    } else if (ui->checkMineur->isChecked()){
        emit selectionCreationCursus(QString("Mineur"));
    } else if (ui->checkTC->isChecked()){
        emit selectionCreationCursus(QString("TC"));
    }
}
