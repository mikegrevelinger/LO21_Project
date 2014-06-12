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
        return enumeration::ErrorNote;
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
        return enumeration::ErrorSaison;
    }

    CategorieUV StringToCategorieUV(const QString& str){
        if (str=="CS") return enumeration::CS;
        if (str=="TM") return enumeration::TM;
        if (str=="TSH") return enumeration::TSH;
        return enumeration::ErrorCategorieUV;
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
        return enumeration::ErrorCivilite;
    }

    Choix StringToChoix(const QString & str)
    {
        if(str=="VEUT") return enumeration::VEUT;
        if(str=="REJ") return enumeration::REJ;
        if(str=="NEUTRE") return enumeration::NEUTRE;
        return enumeration::ErrorChoix;
    }

    QString ChoixToString(Choix c){
        switch(c){
        case enumeration::VEUT: return "VEUT";
        case enumeration::REJ: return "REJ";
        case enumeration::NEUTRE: return"NEUTRE";
        default: return "";
        }
    }

    QString TypeCursusToString(TypeCursus c){
        switch(c){
        case enumeration::TypeTc: return "TypeTc";
        case enumeration::TypeTcAvecUvObligatoire: return "TypeTcAvecUvObligatoire";
        case enumeration::TypeBranche: return "TypeBranche";
        case enumeration::TypeBrancheAvecUvObligatoire: return "TypeBrancheAvecUvObligatoire";
        default: return "";
        }
    }

    TypeCursus StringToTypeCursus(const QString & str){
        if(str=="TypeTc") return enumeration::TypeTc;
        if(str=="TypeTcAvecUvObligatoire") return enumeration::TypeTcAvecUvObligatoire;
        if(str=="TypeBranche") return enumeration::TypeBranche;
        if(str=="TypeBrancheAvecUvObligatoire") return enumeration::TypeBrancheAvecUvObligatoire;
        return enumeration::ErrorTypeCursus;
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
