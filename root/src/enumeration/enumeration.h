#ifndef ENUMERATION_h
#define ENUMERATION_h

#include <QString>

namespace enumeration {
    enum CategorieUV {
        CS = 0,     /* Connaissances Scientifiques */
        TM,     /* Techniques et Methodes */
        TSH,    /* Technologies et Sciences de l'Homme */
        ErrorCategorieUV
    };
    CategorieUV StringToCategorieUV(const QString& str);
    QString CategorieUVToString(CategorieUV c);

    enum Note {
        A = 0,
        B,
        C,
        D,
        E,
        F,
        FX,
        RES,    /* C'est pour ? */
        ABS,    /* Absence */
        EC,     /* en cours */
        INSCRIT,/* UV inscrite : validée par l'utilisateur lors des propositions */
        ErrorNote
    };
    Note StringToNote(const QString & str);
    QString NoteToString(Note n);

    enum Saison {
        Automne = 0,
        Printemps,
        Tout,
        ErrorSaison
    };
    QString SaisonToString(Saison c);
    Saison StringToSaison(const QString & str);

    enum Civilite{
        Monsieur = 0,
        Madame,
        Mademoiselle,
        ErrorCivilite
    };
    QString CiviliteToString(Civilite c);
    Civilite StringToCivilite(const QString & str);

    enum Choix{
        REJ = 0,
        VEUT,
        NEUTRE,
        ErrorChoix
    };
    QString ChoixToString(Choix c);
    Choix StringToChoix(const QString & str);

    enum TypeCursus {
        TypeTc = 0,
        TypeTcAvecUvObligatoire,
        TypeBranche,
        TypeBrancheAvecUvObligatoire,
        ErrorTypeCursus
    };
    QString TypeCursusToString(TypeCursus c);
    TypeCursus StringToTypeCursus(const QString & str);
}

/**
 * QTextStream& operator<<(QTextStream& f, const Categorie& s);
 * Categorie StringToCategorie(const QString& s);
 * QString CategorieToString(Categorie c);
 * QTextStream& operator>>(QTextStream& f, Categorie& cat);
 * inline QTextStream& operator<<(QTextStream& f, const Saison& s) { if (s==Saison::Automne) f<<"A"; else f<<"P"; return f;}
*/

#endif
