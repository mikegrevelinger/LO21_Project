#ifndef CURSUSFACTORY_H
#define CURSUSFACTORY_H

#include "Cursus.h"
#include "./enumeration/enumeration.h"
#include "ErrorManager.h"
#include "DBManager.h"

class CursusFactory : public QObject {
private:
    Q_OBJECT
public:
    CursusFactory();
    Cursus * makeCursus(const int id);
    Cursus * makeCursus(const QString & nomCursus);
    ~CursusFactory();
};

#endif // CURSUSFACTORY_H
