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
    QLabel * label;
    QTableWidget * table;
    QHeaderView * header;
    QLabel * message;
    QStringList headerText;
    QPixmap * searchPixmap;
    QLabel * search;
    QPixmap * ajoutUVPixmap;
    ClickableQLabel * ajoutUV;
public:
    rechercheInstantaneDossier(QWidget *parent = 0);
public slots:
    void slotRechercherDossier(QString p);
    void cellSelected(int nRow, int nCol);
    void ouvrirDialogAjouterDossier();
};

#endif // RECHERCHEINSTANTANEDOSSIER_H
