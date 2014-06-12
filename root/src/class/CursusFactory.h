#ifndef CURSUSFACTORY_H
#define CURSUSFACTORY_H

#include "Cursus.h"
#include "./enumeration/enumeration.h"

class CursusFactory {
public:
    CursusFactory(){}
    Cursus * makeCursus(const int id);
    Cursus * makeCursus(const QString & nomCursus);
};

#endif // CURSUSFACTORY_H
