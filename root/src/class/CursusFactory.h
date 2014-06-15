#ifndef CURSUSFACTORY_H
#define CURSUSFACTORY_H

#include "Cursus.h"
#include "./enumeration/enumeration.h"
#include "ErrorManager.h"
#include "DBManager.h"

/**
 * @brief CursusFactory : design pattern Factory pour crée un Cursus
 *
 * Il faut faire appel à un makeCursus qui permet de créer le Cursus correspondant à :
 *  - l'étudiant en donnant son id
 *  - au nom du cursus
 *
 */

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
