#ifndef DIALOGAJOUTERCURSUSTC_H
#define DIALOGAJOUTERCURSUSTC_H

#include <QDialog>
#include "./class/DBManager.h"

namespace Ui {
    class dialogAjouterCursusTC;
}

class dialogAjouterCursusTC : public QDialog
{
    Q_OBJECT
public:
    explicit dialogAjouterCursusTC(QWidget *parent = 0);
    ~dialogAjouterCursusTC();
private:
    Ui::dialogAjouterCursusTC *ui;
public slots:
    void ajoutTC();
};

#endif // DIALOGAJOUTERCURSUSTC_H
