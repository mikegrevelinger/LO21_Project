#include "popMessage.h"

popMessage::popMessage(const QString & m)
{
    M = new QMessageBox();
    M->setText("Error");
    M->setInformativeText(m);
    M->exec();
}
