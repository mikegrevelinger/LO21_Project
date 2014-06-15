#ifndef DIALOGAJOUTERCURSUS_H
#define DIALOGAJOUTERCURSUS_H

#include <QDialog>
#include "rechercheInstantaneCursus.h"

namespace Ui {
class dialogAjouterCursus;
}

class dialogAjouterCursus : public QDialog
{
    Q_OBJECT

public:
    dialogAjouterCursus(class rechercheInstantaneCursus * p, QWidget * parent = 0);
    ~dialogAjouterCursus();
private:
    Ui::dialogAjouterCursus *ui;
public slots:
    void ajoutDossier();
signals:
    void selectionCreationCursus(QString p);
};

#endif // DIALOGAJOUTERCURSUS_H
