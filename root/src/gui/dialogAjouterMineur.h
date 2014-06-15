#ifndef DIALOGAJOUTERMINEUR_H
#define DIALOGAJOUTERMINEUR_H

#include <QDialog>

namespace Ui {
class dialogAjouterMineur;
}

class dialogAjouterMineur : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterMineur(QWidget *parent = 0);
    ~dialogAjouterMineur();

private:
    Ui::dialogAjouterMineur *ui;
};

#endif // DIALOGAJOUTERMINEUR_H
