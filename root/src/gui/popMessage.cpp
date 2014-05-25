#include "popMessage.h"

popMessage::popMessage(const QString & title, const QString & text)
{
    QMessageBox::Icon icon;
    if (title == QString("Error")) {
        icon = QMessageBox::Critical;
    } else {
        icon = QMessageBox::Information;
    }
    M = new QMessageBox(icon,title,text,QMessageBox::Ok);
    M->exec();
}
