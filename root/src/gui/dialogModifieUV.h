#ifndef DIALOGMODIFIEUV_H
#define DIALOGMODIFIEUV_H

#include <QDialog>
#include "./class/DBManager.h"

namespace Ui {
class dialogModifieUV;
}

class dialogModifieUV : public QDialog
{
    Q_OBJECT
private:
    Ui::dialogModifieUV *ui;
public:
    explicit dialogModifieUV(const QString &n, QWidget *parent = 0);
    ~dialogModifieUV();
public slots:
    void aEteAccepte();
};

#endif // DIALOGMODIFIEUV_H
