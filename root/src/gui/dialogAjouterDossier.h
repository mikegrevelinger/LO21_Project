#ifndef DIALOGAJOUTERDOSSIER_H
#define DIALOGAJOUTERDOSSIER_H

#include <QDialog>
#include "./enumeration/enumeration.h"
#include "./class/DBManager.h"
#include <QStringList>

namespace Ui {
class dialogAjouterDossier;
}

class dialogAjouterDossier : public QDialog
{
    Q_OBJECT
private:
    Ui::dialogAjouterDossier *ui;
public:
    explicit dialogAjouterDossier(QWidget *parent = 0);
    ~dialogAjouterDossier();
public slots:
    void ajoutDossier();
};

#endif // DIALOGAJOUTERDOSSIER_H
