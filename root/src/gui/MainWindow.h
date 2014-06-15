#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rechercheInstantaneUV.h"
#include "rechercheInstantaneDossier.h"
#include "menuIcon.h"
#include "./class/HandlerSingleton.h"
#include "dialogAjouterCursus.h"
#include "dialogAjouterDossier.h"
#include "dialogAjouterUV.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    class rechercheInstantaneUV * rUV;
    class rechercheInstantaneDossier * rDossier;
public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();
public slots:
    void afficheRechercheInstantaneUV();
    void afficheRechercheInstantaneDossier();
};

#endif // MAINWINDOW_H
