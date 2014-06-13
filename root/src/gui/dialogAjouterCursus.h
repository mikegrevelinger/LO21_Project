#ifndef DIALOGAJOUTERCURSUS_H
#define DIALOGAJOUTERCURSUS_H

#include <QDialog>

namespace Ui {
class dialogAjouterCursus;
}

class dialogAjouterCursus : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAjouterCursus(QWidget *parent = 0);
    ~dialogAjouterCursus();

private:
    Ui::dialogAjouterCursus *ui;
};

#endif // DIALOGAJOUTERCURSUS_H
