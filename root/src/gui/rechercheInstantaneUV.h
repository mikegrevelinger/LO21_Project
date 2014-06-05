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

#include "./class/UVManager.h"
#include "./class/DBManager.h"

class rechercheInstantaneUV : public QWidget
{
    Q_OBJECT
private:
    QRegExp regexRechercheUV;
    QLineEdit * l;
    QGridLayout * layout;
    QLabel * label;
    QTableWidget * table;
    QHeaderView * header;
    QLabel * message;
    QStringList headerText;
public:
    rechercheInstantaneUV(QWidget *parent = 0);
public slots:
    void slotRechercherUV(QString p);
    void cellSelected(int nRow, int nCol);
};


#endif // RECHERCHEINSTANTANEUV_H
