#include "dialogAjouterDossier.h"
#include "ui_dialogAjouterDossier.h"

dialogAjouterDossier::dialogAjouterDossier(QWidget *parent) : QDialog(parent), ui(new Ui::dialogAjouterDossier)
{
    ui->setupUi(this);
    for (int i = enumeration::Monsieur; i != enumeration::ErrorCivilite;i++){
        ui->civi->addItem(enumeration::CiviliteToString(static_cast<enumeration::Civilite>(i)));
    }
    for (int i = enumeration::Automne; i != enumeration::ErrorSaison;i++){
        ui->seme->addItem(enumeration::SaisonToString(static_cast<enumeration::Saison>(i)));
    }
    DBManager & dbm = DBManager::getInstance();
    QStringList & q = dbm.rechercheNomCursus();
    for (int i = 0; i < q.size(); ++i){
        ui->cursu->addItem(q[i]);
    }
    q.clear();
    ui->filiereEtu->addItem(QString(""));
    q = dbm.rechercheNomCursusFiliere();
    for (int i = 0; i < q.size(); ++i){
        ui->filiereEtu->addItem(q[i]);
    }
    q.clear();
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(ajoutDossier()));
}

dialogAjouterDossier::~dialogAjouterDossier()
{
    delete ui;
}


void dialogAjouterDossier::ajoutDossier(){
    DBManager & dbm = DBManager::getInstance();
    /*
    qDebug() <<"lol"<<ui->filiereEtu->currentText();
    qDebug() <<ui->lineNomEtu->text();
    qDebug() <<ui->linePrenomEtu->text();
    qDebug() <<ui->civi->currentText();
    qDebug() <<ui->lineNatioEtu->text();
    qDebug() <<ui->dateEdit->date();
    qDebug() <<ui->seme->currentText();
    qDebug() <<ui->spinAnneeEtu->value();
    qDebug() <<ui->creditEquiTotal->value();
    qDebug() <<ui->creditEquiCS->value();
    qDebug() <<ui->creditEquiTM->value();
    qDebug() <<ui->creditEquiTSH->value();
    qDebug() <<ui->cursu->currentText();
    qDebug() <<ui->spinSeme->value();
    qDebug() <<ui->creditEtranTotal->value();
    qDebug() <<ui->creditEtranCS->value();
    qDebug() <<ui->creditEtranTM->value();
    qDebug() <<ui->creditEquiTSH->value();
    qDebug() <<ui->filiereEtu->currentText();
    */
    dbm.ajouteETU(ui->lineNomEtu->text(),ui->linePrenomEtu->text(), enumeration::StringToCivilite(ui->civi->currentText()),ui->lineNatioEtu->text(),
                 ui->dateEdit->date(),enumeration::StringToSaison(ui->seme->currentText()),
                 ui->spinAnneeEtu->value(),ui->creditEquiTotal->value(),ui->creditEquiCS->value(),
                 ui->creditEquiTM->value(),ui->creditEquiTSH->value(),ui->cursu->currentText(),
                 ui->spinSeme->value(),ui->creditEtranTotal->value(),ui->creditEtranCS->value(),
                 ui->creditEtranTM->value(),ui->creditEquiTSH->value(),ui->filiereEtu->currentText());
}

