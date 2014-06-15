#ifndef DIALOGAJOUTERCURSUSBRANCHE_H
#define DIALOGAJOUTERCURSUSBRANCHE_H

#include <QDialog>
#include "./class/DBManager.h"

namespace Ui {
class dialogAjouterCursusBranche;
}

class dialogAjouterCursusBranche : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterCursusBranche(QWidget *parent = 0);
    ~dialogAjouterCursusBranche();
private:
    Ui::dialogAjouterCursusBranche *ui;
public slots:
    void ajoutBranche();
};

#endif // DIALOGAJOUTERCURSUSBRANCHE_H
