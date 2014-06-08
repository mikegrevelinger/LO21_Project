#ifndef ENUMERATION_h
#define ENUMERATION_h

#include <QString>

namespace enumeration {
    enum CategorieUV {
        CS,     /* Connaissances Scientifiques */
        TM,     /* Techniques et Methodes */
        TSH     /* Technologies et Sciences de l'Homme */
    };
    CategorieUV StringToCategorieUV(const QString& str);
    QString CategorieUVToString(CategorieUV c);

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
        EC,     /* en cours */
        INSCRIT /* UV inscrite : validée par l'utilisateur lors des propositions */
    };
    Note StringToNote(const QString & str);
    QString NoteToString(Note n);

    enum Saison {
        Automne,
        Printemps,
        Tout
    };
    QString SaisonToString(Saison c);
    Saison StringToSaison(const QString & str);

    enum Civilite{
        Monsieur,
        Madame,
        Mademoiselle
    };
    QString CiviliteToString(Civilite c);
    Civilite StringToCivilite(const QString & str);
}

/**
 * QTextStream& operator<<(QTextStream& f, const Categorie& s);
 * Categorie StringToCategorie(const QString& s);
 * QString CategorieToString(Categorie c);
 * QTextStream& operator>>(QTextStream& f, Categorie& cat);
 * inline QTextStream& operator<<(QTextStream& f, const Saison& s) { if (s==Saison::Automne) f<<"A"; else f<<"P"; return f;}
*/

#endif
