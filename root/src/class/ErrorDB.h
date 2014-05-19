#ifndef ERRORDB_H
#define ERRORDB_H

#include <QString>
#include <QObject>
#include <QMessageBox>

class ErrorDB
{
private:
    QString info;   //Description de l'erreur
    QMessageBox * msgBox;
public:
    ErrorDB(const QString &message="") ;
    const QString & what() const { return info; }
    ~ErrorDB(){}
};

#endif // ERRORDB_H
