#ifndef RECHERCHEINSTANTANEUV_H
#define RECHERCHEINSTANTANEUV_H

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
#include "dialogModifieUV.h"
#include "MainWindow.h"

class rechercheInstantaneUV : public QWidget
{
    Q_OBJECT
private:
    QRegExp regexRechercheUV;
    QLineEdit * l;
    QGridLayout * layout;
    QTableWidget * table;
    QHeaderView * header;
    QStringList headerText;
    QPixmap * ajoutUVPixmap;
    ClickableQLabel * ajoutUV;
public:
    rechercheInstantaneUV(QWidget *parent = 0);
    ~rechercheInstantaneUV();
signals:
public slots:
    void slotRechercherUV(QString p);
    void ouvrirDialogModifieUV(int nRow, int nCol);
    void ouvrirDialogAjouterUV();
};


#endif // RECHERCHEINSTANTANEUV_H
