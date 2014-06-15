#ifndef DIALOGAJOUTERUVTC_H
#define DIALOGAJOUTERUVTC_H

#include <QDialog>
#include "./class/DBManager.h"

namespace Ui {
class dialogAjouterUVTC;
}

class dialogAjouterUVTC : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterUVTC(QWidget *parent = 0);
    ~dialogAjouterUVTC();
private:
    Ui::dialogAjouterUVTC *ui;
public slots:
    void ajouteUVTC();
};

#endif // DIALOGAJOUTERUVTC_H
