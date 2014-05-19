#ifndef ERRORDB_H
#define ERRORDB_H

#include <QString>
using namespace std;

class ErrorDB
{
private:
    QString info;   //Description de l'erreur
public:
    ErrorDB(const QString & message=""):info(message) {}
    virtual const QString & what() const { return info.c_str(); }
    virtual ~ErrorDB() {}
};

#endif // ERRORDB_H
