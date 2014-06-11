#include <QTextStream>

#include "enumeration.h"

namespace enumeration{
    Note StringToNote(const QString & str){
        if (str=="A") return enumeration::A;
        if (str=="B") return enumeration::B;
        if (str=="C") return enumeration::C;
        if (str=="D") return enumeration::D;
        if (str=="E") return enumeration::E;
        if (str=="F") return enumeration::F;
        if (str=="FX") return enumeration::FX;
        if (str=="ABS") return enumeration::ABS;
        if (str=="EC") return enumeration::EC;
        if (str=="INSCRIT") return enumeration::INSCRIT;
        if (str=="RES") return enumeration::RES;
    }

    QString NoteToString(Note n){
        switch(n){
            case enumeration::A: return "A";
            case enumeration::B: return "B";
            case enumeration::C: return "C";
            case enumeration::D: return "D";
            case enumeration::E: return "E";
            case enumeration::F: return "F";
            case enumeration::FX: return "FX";
            case enumeration::ABS: return "ABS";
            case enumeration::EC: return "EC";
            case enumeration::INSCRIT: return "INSCRIT";
            case enumeration::RES: return "RES";
        default: return "";
        }
    }

    QString SaisonToString(Saison s){
        switch(s){
            case enumeration::Automne: return "Automne";
            case enumeration::Printemps: return "Printemps";
            case enumeration::Tout: return "Tout";
        default: return "";
        }
    }

    Saison StringToSaison(const QString & str) {
        if (str=="Automne") return enumeration::Automne;
        if (str=="Printemps") return enumeration::Printemps;
        if (str=="Tout") return enumeration::Tout;
    }

    CategorieUV StringToCategorieUV(const QString& str){
        if (str=="CS") return enumeration::CS;
        if (str=="TM") return enumeration::TM;
        if (str=="TSH") return enumeration::TSH;
    }

    QString CategorieUVToString(CategorieUV c){
        switch(c){
            case enumeration::CS: return "CS";
            case enumeration::TM: return "TM";
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

    Choix StringToChoix(const QString & str)
    {
        if(str=="VEUT") return enumeration::VEUT;
        if(str=="REJ") return enumeration::REJ;
        if(str=="NEUTRE") return enumeration::NEUTRE;
    }

    QString ChoixToString(Choix c){
        switch(c){
        case enumeration::VEUT: return "VEUT";
        case enumeration::REJ: return "REJ";
        case enumeration::NEUTRE: return"NEUTRE";
        }
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
