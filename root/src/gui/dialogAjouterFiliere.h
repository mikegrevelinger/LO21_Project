#ifndef DIALOGAJOUTERFILIERE_H
#define DIALOGAJOUTERFILIERE_H

#include <QDialog>

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
};

#endif // DIALOGAJOUTERFILIERE_H
