#include <QTextStream>

#include "enumeration.h"
#include "./class/ErrorManager.h"

namespace enumeration{
    CategorieUV StringToCategorieUV(const QString& str){
        if (str=="CS") return enumeration::CS;
        if (str=="TM") return enumeration::TM;
        if (str=="SP") return enumeration::SP;
        if (str=="TSH") return enumeration::TSH;
    }

    QString CategorieUVToString(CategorieUV c){
        switch(c){
        case enumeration::CS: return "CS";
        case enumeration::TM: return "TM";
        case enumeration::SP: return "SP";
        case enumeration::TSH: return "TSH";
        default: return "";
        }
    }

    QString CiviliteToString(Civilite c){
        switch (c){
        case enumeration::Monsieur: return "Monsieur";
        case enumeration::Madame: return "Madame";
        case enumeration::Mademoiselle: return "Mademoiselle";
        default: return "";
        }
    }

    Civilite StringToCivilite(const QString & str){
        if (str=="Monsieur") return enumeration::Monsieur;
        if (str=="Madame") return enumeration::Madame;
        if (str=="Mademoiselle") return enumeration::Mademoiselle;
    }
}




/*
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
*/
