#ifndef CLICKABLEQLABEL_H
#define CLICKABLEQLABEL_H

#include <QLabel>

class ClickableQLabel : public QLabel
{
    Q_OBJECT
protected:
    void mousePressEvent (QMouseEvent * event) ;
public:
    ClickableQLabel(QWidget * parent = 0);
    ClickableQLabel(const QString & q, QWidget * parent = 0);
    ~ClickableQLabel();
signals:
    void clicked();
public slots:
    void hasBeenClicked();
};

#endif // CLICKABLEQLABEL_H
