#ifndef UVMANAGER_H
#define UVMANAGER_H

/*
class UVManager
{
private:
    UV** uvs;
    unsigned int nbUV;
    unsigned int nbMaxUV;
    void addItem(UV* uv);
    bool modification;
    UV* trouverUV(const QString& c) const;
    UVManager(const UVManager);
    void operator=(const UVManager);
    UVManager();
    ~UVManager();
    QString file;
    friend struct Handler;
    static Handler handler;

public:
    void load(const QString& f);
    void save(const QString& f);
    static UVManager& getInstance();
    static void libererInstance();
    void ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p);
    const UV& getUV(const QString& code) const;
    UV& getUV(const QString& code);

    class Iterator {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Iterator(UV** u, unsigned nb):currentUV(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentUV(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw UTProfilerException("error, next on an iterator which is done");
            nbRemain--;
            currentUV++;
        }
        UV& current() const {
            if (isDone())
                throw UTProfilerException("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    Iterator getIterator() {
        return Iterator(uvs,nbUV);
    }

    class iterator {
        UV** current;
        iterator(UV** u):current(u){}
        friend class UVManager;
    public:
        iterator():current(0){};
        UV& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(uvs); }
    iterator end() { return iterator(uvs+nbUV); }

    class FilterIterator {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Categorie categorie;
        FilterIterator(UV** u, unsigned nb, Categorie c):currentUV(u),nbRemain(nb),categorie(c){
            while(nbRemain>0 && (*currentUV)->getCategorie()!=categorie){
                nbRemain--; currentUV++;
            }
        }
    public:
        FilterIterator():nbRemain(0),currentUV(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw UTProfilerException("error, next on an iterator which is done");
            do {
                nbRemain--; currentUV++;
            }while(nbRemain>0 && (*currentUV)->getCategorie()!=categorie);
        }
        UV& current() const {
            if (isDone())
                throw UTProfilerException("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    FilterIterator getFilterIterator(Categorie c) {
        return FilterIterator(uvs,nbUV,c);
    }
};

*/

#endif // UVMANAGER_H
