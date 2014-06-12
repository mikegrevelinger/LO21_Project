#include "menuIcon.h"

menuIcon::menuIcon(QWidget *parent) :
    QWidget(parent)
{
    l = new QGridLayout;
    uvPixmap = new QPixmap(QString("iconUV.png"));
    dossierPixmap = new QPixmap(QString("iconDossier.png"));
    cursusPixmap = new QPixmap(QString("iconCursus.png"));
    previsionPixmap = new QPixmap(QString("iconPrevision.png"));
    uvLabel = new ClickableQLabel(QString("UV"));
    cursusLabel = new ClickableQLabel(QString("Cursus"));
    dossierLabel = new ClickableQLabel(QString("Dossier"));
    previsionLabel = new ClickableQLabel(QString("Prevision"));
    uv = new ClickableQLabel();
    uv->setPixmap(*uvPixmap);
    uv->setFixedSize(QSize(32,32));
    cursus = new ClickableQLabel();
    cursus->setPixmap(*cursusPixmap);
    cursus->setFixedSize(QSize(32,32));
    dossier = new ClickableQLabel();
    dossier->setPixmap(*dossierPixmap);
    dossier->setFixedSize(QSize(32,32));
    prevision = new ClickableQLabel();
    prevision->setPixmap(*previsionPixmap);
    prevision->setFixedSize(QSize(32,32));
    l->addWidget(uv,0,0,1,1,Qt::AlignCenter);
    l->addWidget(dossier,0,1,1,1,Qt::AlignCenter);
    l->addWidget(cursus,0,2,1,1,Qt::AlignCenter);
    l->addWidget(prevision,0,3,1,1,Qt::AlignCenter);
    l->addWidget(uvLabel,1,0,1,1,Qt::AlignCenter);
    l->addWidget(dossierLabel,1,1,1,1,Qt::AlignCenter);
    l->addWidget(cursusLabel,1,2,1,1,Qt::AlignCenter);
    l->addWidget(previsionLabel,1,3,1,1,Qt::AlignCenter);
    setLayout(l);
}
