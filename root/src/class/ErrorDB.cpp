#include "ErrorDB.h"

ErrorDB::ErrorDB(const QString & message):info(message){
    msgBox = new QMessageBox ;
    msgBox->setText(info);
    msgBox->setInformativeText("Veuillez rééssayer.");
    //msgBox->setStandardButtons(QMessageBox::Cancel);
    msgBox->exec();
}


