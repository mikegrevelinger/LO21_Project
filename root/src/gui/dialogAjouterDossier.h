#ifndef DIALOGAJOUTERDOSSIER_H
#define DIALOGAJOUTERDOSSIER_H

#include <QDialog>

namespace Ui {
class dialogAjouterDossier;
}

class dialogAjouterDossier : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterDossier(QWidget *parent = 0);
    ~dialogAjouterDossier();
private:
    Ui::dialogAjouterDossier *ui;
};

#endif // DIALOGAJOUTERDOSSIER_H
