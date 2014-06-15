#ifndef DIALOGAJOUTERCURSUSBRANCHE_H
#define DIALOGAJOUTERCURSUSBRANCHE_H

#include <QDialog>

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
};

#endif // DIALOGAJOUTERCURSUSBRANCHE_H
