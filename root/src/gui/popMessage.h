#ifndef POPMESSAGE_H
#define POPMESSAGE_H

#include <QString>
#include <QMessageBox>

class popMessage: public QWidget
{
    QMessageBox * M;
public:
    popMessage(const QString & title, const QString & text);
};

#endif // POPMESSAGE_H
