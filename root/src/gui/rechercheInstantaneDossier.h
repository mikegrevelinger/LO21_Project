#ifndef RECHERCHEINSTANTANEDOSSIER_H
#define RECHERCHEINSTANTANEDOSSIER_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QRegExp>
#include <QVector>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QPixmap>

#include "./class/UVManager.h"
#include "./class/DBManager.h"
#include "ClickableQLabel.h"
#include "MainWindow.h"

class rechercheInstantaneDossier : public QWidget
{
    Q_OBJECT
private:
    QRegExp regexRechercheDossier;
    QLineEdit * l;
    QGridLayout * layout;
    QTableWidget * table;
    QHeaderView * header;
    QStringList headerText;
    QPixmap * ajoutPixmap;
    ClickableQLabel * ajout;
public:
    rechercheInstantaneDossier(QWidget *parent = 0);
    ~rechercheInstantaneDossier();
signals:
public slots:
    void slotRechercherDossier(QString p);
    //void ouvrirDialogModifieDossier(int nRow, int nCol);
    void ouvrirDialogAjouterDossier();
};

#endif // RECHERCHEINSTANTANEDOSSIER_H
