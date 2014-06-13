#include "dialogAjouterCursus.h"
#include "ui_dialogAjouterCursus.h"

dialogAjouterCursus::dialogAjouterCursus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterCursus)
{
    ui->setupUi(this);
}

dialogAjouterCursus::~dialogAjouterCursus()
{
    delete ui;
}
