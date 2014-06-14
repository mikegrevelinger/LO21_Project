#ifndef MENUICON_H
#define MENUICON_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QSize>
#include "ClickableQLabel.h"
#include "MainWindow.h"


class menuIcon : public QWidget
{
    Q_OBJECT
private:
    QGridLayout * l;
    QPixmap * uvPixmap;
    QPixmap * dossierPixmap;
    QPixmap * cursusPixmap;
    QPixmap * previsionPixmap;
    ClickableQLabel * uvLabel;
    ClickableQLabel * cursusLabel;
    ClickableQLabel * dossierLabel;
    ClickableQLabel * previsionLabel;
    ClickableQLabel * uv;
    ClickableQLabel * cursus;
    ClickableQLabel * dossier;
    ClickableQLabel * prevision;
public:
    menuIcon(class MainWindow * c ,QWidget * parent = 0);
signals:

public slots:

};

#endif // MENUICON_H
