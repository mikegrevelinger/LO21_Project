#ifndef POPMESSAGE_H
#define POPMESSAGE_H

#include <QString>
#include <QMessageBox>

class popMessage: public QWidget
{
    QMessageBox * M;
public:
    popMessage(const QString & m);
};

#endif // POPMESSAGE_H
