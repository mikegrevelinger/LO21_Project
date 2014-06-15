#include "dialogAjouterCursusTC.h"
#include "ui_dialogAjouterCursusTC.h"

dialogAjouterCursusTC::dialogAjouterCursusTC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAjouterCursusTC)
{
    ui->setupUi(this);
}

dialogAjouterCursusTC::~dialogAjouterCursusTC()
{
    delete ui;
}
