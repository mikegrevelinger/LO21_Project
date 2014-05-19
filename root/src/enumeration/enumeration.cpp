#include <QTextStream>

#include "enumeration.h"

/*
QTextStream& operator>>(QTextStream& f, CategorieUV& cat){
    QString str;
    f>>str;
    if (str=="CS") cat=CategorieUV::CS;
    else
    if (str=="TM") cat=CategorieUV::TM;
    else
    if (str=="SP") cat=CategorieUV::SP;
    else
    if (str=="TSH") cat=CategorieUV::TSH;
    else {
        throw UTProfilerException("erreur, lecture CategorieUV");
    }
    return f;
}

CategorieUV StringToCategorieUV(const QString& str){
    if (str=="CS") return CategorieUV::CS;
    else
    if (str=="TM") return CategorieUV::TM;
    else
    if (str=="SP") return CategorieUV::SP;
    else
    if (str=="TSH") return CategorieUV::TSH;
    else {
        throw UTProfilerException(QString("erreur, StringToCategorieUV, CategorieUV ")+str+" inexistante");
    }
}

QString CategorieUVToString(CategorieUV c){
    switch(c){
    case CategorieUV::CS: return "CS";
    case CategorieUV::TM: return "TM";
    case CategorieUV::SP: return "SP";
    case CategorieUV::TSH: return "TSH";
    default: throw UTProfilerException("erreur, CategorieUV non traitee");
    }
}

QTextStream& operator<<(QTextStream& f, const CategorieUV& cat){
    switch(cat){
    case CategorieUV::CS: f<<"CS"; break;
    case CategorieUV::TM: f<<"TM"; break;
    case CategorieUV::SP: f<<"SP"; break;
    case CategorieUV::TSH: f<<"TSH"; break;
    default: throw UTProfilerException("erreur, CategorieUV non traitee");
    }
    return f;
}

*/
