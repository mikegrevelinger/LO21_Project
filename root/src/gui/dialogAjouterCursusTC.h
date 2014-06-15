#ifndef DIALOGAJOUTERCURSUSTC_H
#define DIALOGAJOUTERCURSUSTC_H

#include <QDialog>

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
};

#endif // DIALOGAJOUTERCURSUSTC_H
