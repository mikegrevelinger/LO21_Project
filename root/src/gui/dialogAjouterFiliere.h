#ifndef DIALOGAJOUTERFILIERE_H
#define DIALOGAJOUTERFILIERE_H

#include <QDialog>
#include "./class/DBManager.h"

namespace Ui {
class dialogAjouterFiliere;
}

class dialogAjouterFiliere : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterFiliere(QWidget *parent = 0);
    ~dialogAjouterFiliere();

private:
    Ui::dialogAjouterFiliere *ui;
public slots:
    void ajouteFiliere();
};

#endif // DIALOGAJOUTERFILIERE_H
