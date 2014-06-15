#ifndef ENUMERATION_h
#define ENUMERATION_h

#include <QString>

/**
 * @brief Enumeration : namespace contenant tous les types énumérés
 *
 * Dans chaque enum, nous avons ajouter le cas "Error..." pour pouvoir modéliser les cas où il y a un problème.
 */

namespace enumeration {
    //! Enumeration des 4 catégories d'UV possibles
    enum CategorieUV {
        CS = 0,     /// Connaissances Scientifiques
        TM,         /// Techniques et Methodes
        TSH,        /// Technologies et Sciences de l'Homme
        ErrorCategorieUV
    };
    CategorieUV StringToCategorieUV(const QString& str); ///Passage de QString au type CategorieUV
    QString CategorieUVToString(CategorieUV c);///Passage du type CategorieUV à QString

    //! Enumeration du type des notes possibles utilisés
    enum Note {
        A = 0,
        B,
        C,
        D,
        E,
        F,
        FX,
        RES,    /* C'est pour ? */
        ABS,    /// Absence
        EC,     /// En cours
        INSCRIT,/// UV inscrite : validée par l'utilisateur lors des propositions
        ErrorNote
    };
    Note StringToNote(const QString & str); ///Passage de QString au type Note
    QString NoteToString(Note n); ///Passage du type Note à QString

    //! Enumeration des saisons où les UV peuvent être enseignés
    enum Saison {
        Automne = 0,
        Printemps,
        Tout, /// Ceci signifie que l'UV est enseigné en Automne et au Printemps
        ErrorSaison
    };
    QString SaisonToString(Saison c); ///Passage du type Saison à QString
    Saison StringToSaison(const QString & str); ///Passage de QString au type Saison

    //! Enumeration des civilités
    enum Civilite{
        Monsieur = 0,
        Madame,
        Mademoiselle,
        ErrorCivilite
    };
    QString CiviliteToString(Civilite c); ///Passage du type Civilite à QString
    Civilite StringToCivilite(const QString & str); ///Passage de QString au type Civilite

    //! Enumeration des différents choix proposés à l'étudiant pour la prévision
    enum Choix{
        REJ = 0, /// L'étudiant ne veut pas faire l'UV.
        VEUT, /// L'étudiant aimerait faire l'UV.
        NEUTRE, /// L'étudiant n'a pas de préférence.
        ErrorChoix
    };
    QString ChoixToString(Choix c); ///Passage du type Choix à QString
    Choix StringToChoix(const QString & str); ///Passage de QString au type Choix

    //! Les types de cursus qui ont été modélisés et réalisés. Il en existe bien sûr d'autres qui peuvent être ajouter.
    enum TypeCursus {
        TypeTc = 0,
        TypeTcAvecUvObligatoire,
        TypeBranche,
        TypeBrancheAvecUvObligatoire,
        ErrorTypeCursus
    };
    QString TypeCursusToString(TypeCursus c); ///Passage du type TypeCursus à QString
    TypeCursus StringToTypeCursus(const QString & str); ///Passage de QString au type TypeCursus
}


#endif
