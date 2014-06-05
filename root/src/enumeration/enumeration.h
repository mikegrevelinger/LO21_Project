#ifndef ENUMERATION_h
#define ENUMERATION_h

#include <QString>

namespace enumeration {
    enum CategorieUV {
        CS,     /* Connaissances Scientifiques */
        TM,     /* Techniques et Methodes */
        TSH,    /* Technologies et Sciences de l'Homme */
        SP     /* Stage et Projet */
    };

    enum Note {
        A,
        B,
        C,
        D,
        E,
        F,
        FX,
        RES,    /* C'est pour ? */
        ABS,    /* Absence */
        EC     /* en cours */
    };

    enum Saison {
        Automne,
        Printemps
    };
    enum Civilite{
        Monsieur,
        Madame,
        Mademoiselle
    };

    CategorieUV StringToCategorieUV(const QString& str);
    QString CategorieUVToString(CategorieUV c);
}

/**
 * QTextStream& operator<<(QTextStream& f, const Categorie& s);
 * Categorie StringToCategorie(const QString& s);
 * QString CategorieToString(Categorie c);
 * QTextStream& operator>>(QTextStream& f, Categorie& cat);
 * inline QTextStream& operator<<(QTextStream& f, const Saison& s) { if (s==Saison::Automne) f<<"A"; else f<<"P"; return f;}
*/

#endif
