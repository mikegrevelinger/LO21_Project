#ifndef DIALOGAJOUTERUV_H
#define DIALOGAJOUTERUV_H

#include <QDialog>

#include "./class/UVManager.h"
#include "./enumeration/enumeration.h"

namespace Ui {
class dialogAjouterUV;
}

class dialogAjouterUV : public QDialog
{
    Q_OBJECT
private:
    Ui::dialogAjouterUV *ui;
public:
    explicit dialogAjouterUV(QWidget *parent = 0);
    ~dialogAjouterUV();
public slots:
    void ajoutUV();
};

#endif // DIALOGAJOUTERUV_H
