#ifndef DIALOGAJOUTERUV_H
#define DIALOGAJOUTERUV_H

#include <QDialog>

namespace Ui {
class dialogAjouterUV;
}

class dialogAjouterUV : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterUV(QWidget *parent = 0);
    ~dialogAjouterUV();

private:
    Ui::dialogAjouterUV *ui;
};

#endif // DIALOGAJOUTERUV_H
