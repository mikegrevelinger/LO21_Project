#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Baptiste NOGARET - Mike GREVELINGER");
    ui->LayoutBody->addWidget(new rechercheInstantaneUV(this));
    ui->groupBoxLayout->addWidget(new menuIcon(this,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficheRechercheInstantane(){
    qDebug("LOL");
}

