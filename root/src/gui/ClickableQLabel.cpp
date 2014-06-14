#include "ClickableQLabel.h"

ClickableQLabel::ClickableQLabel(QWidget * parent) : QLabel(parent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(hasBeenClicked()));
}

ClickableQLabel::ClickableQLabel(const QString & q, QWidget * parent) : QLabel(parent)
{
    this->setText(q);
    QObject::connect(this, SIGNAL(clicked()),this, SLOT(hasBeenClicked()));
}


ClickableQLabel::~ClickableQLabel()
{
}

void ClickableQLabel::mousePressEvent (QMouseEvent * event)
{
    emit clicked();
}

void ClickableQLabel::hasBeenClicked() {
    qDebug("Clicked");
}
