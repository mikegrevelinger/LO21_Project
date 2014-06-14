#include "menuIcon.h"

menuIcon::menuIcon(MainWindow * c, QWidget *parent) : QWidget(parent) {
    l = new QGridLayout;
    uvPixmap = new QPixmap(QString("iconUV.png"));
    dossierPixmap = new QPixmap(QString("iconDossier.png"));
    cursusPixmap = new QPixmap(QString("iconCursus.png"));
    previsionPixmap = new QPixmap(QString("iconPrevision.png"));
    uvLabel = new ClickableQLabel(QString("UV"),this);
    cursusLabel = new ClickableQLabel(QString("Cursus"),this);
    dossierLabel = new ClickableQLabel(QString("Dossier"),this);
    previsionLabel = new ClickableQLabel(QString("Prevision"),this);
    uv = new ClickableQLabel(this);
    uv->setPixmap(*uvPixmap);
    uv->setFixedSize(QSize(32,32));
    cursus = new ClickableQLabel(this);
    cursus->setPixmap(*cursusPixmap);
    cursus->setFixedSize(QSize(32,32));
    dossier = new ClickableQLabel(this);
    dossier->setPixmap(*dossierPixmap);
    dossier->setFixedSize(QSize(32,32));
    prevision = new ClickableQLabel(this);
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
    QObject::connect(uvLabel,SIGNAL(clicked()),c,SLOT(afficheRechercheInstantane()));
    /*
     * à uv ou uvlabel --> connecter afficheRechercheInstantaneUV
     * à cursus ou cursuslabel --> connecter afficheRechercheInstantaneCursus
     * à dossier ou dossierLabel --> connecter afficheRechercheInstantaneDossier
     * à prevision ou previsionLabel --> connecter afficheRechercheInstantanePrevision
     *
     */
}
