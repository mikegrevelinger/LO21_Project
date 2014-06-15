#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Baptiste NOGARET - Mike GREVELINGER");
    rUV = new rechercheInstantaneUV(this);
    ui->LayoutBody->addWidget(rUV);
    qDebug() << ui->LayoutBody->indexOf(rUV);
    ui->groupBoxLayout->addWidget(new menuIcon(this,this));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete rUV;
    delete rDossier;
}

void MainWindow::afficheRechercheInstantaneUV(){
    delete ui->LayoutBody->takeAt(0);
    rUV = new rechercheInstantaneUV(this);
    ui->LayoutBody->addWidget(rUV);
}

void MainWindow::afficheRechercheInstantaneDossier(){
    delete ui->LayoutBody->takeAt(0);
    rDossier = new rechercheInstantaneDossier(this);
    ui->LayoutBody->addWidget(rDossier);
}

