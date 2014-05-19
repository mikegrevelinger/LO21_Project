#ifndef ENUMITERATOR_H
#define ENUMITERATOR_H

/** Pour cree un EnumIterator : passer par getFirst */

template<typename EnumType>
class EnumIterator
{
    static_assert(is_enum<EnumType>::value, "EnumType have to be an enum");
    EnumType value;
    EnumIterator(EnumType val):value(val){}
public:
    static EnumIterator getFirst() { return EnumIterator(EnumType::first); }
    bool isDone() const { return value>EnumType::last; }
    EnumType current() const { return value; }
    void next() { value=(EnumType)(std::underlying_type<EnumType>::type(value)+1); }
};

typedef EnumIterator<Note> NoteIterator;
typedef EnumIterator<Categorie> CategorieIterator;
typedef EnumIterator<Saison> SaisonIterator;


#endif // ENUMITERATOR_H
