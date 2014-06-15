#ifndef RECHERCHEINSTANTANECURSUS_H
#define RECHERCHEINSTANTANECURSUS_H

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

#include "dialogAjouterCursusBranche.h"
#include "dialogAjouterCursusTC.h"
#include "dialogAjouterFiliere.h"
#include "dialogAjouterMineur.h"
#include "dialogAjouterUVTC.h"

class rechercheInstantaneCursus : public QWidget
{
    Q_OBJECT
private:
    QRegExp regexRechercheCursus;
    QLineEdit * l;
    QGridLayout * layout;
    QTableWidget * table;
    QHeaderView * header;
    QStringList headerText;
    QPixmap * ajoutPixmap;
    ClickableQLabel * ajout;
    ClickableQLabel * ap;
public:
    rechercheInstantaneCursus(QWidget *parent = 0);
    ~rechercheInstantaneCursus();
signals:
public slots:
    void slotRechercherCursus(QString p);
    //void ouvrirDialogModifieCursus(int nRow, int nCol);
    void ouvrirDialogAjouterCursus();
    void ouvrirDialogAjouterCursusBLA(QString a);
    void ouvrirDialogAjouterUVTC();
};

#endif // RECHERCHEINSTANTANECURSUS_H
