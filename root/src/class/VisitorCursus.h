#ifndef VISITORCURSUS_H
#define VISITORCURSUS_H

#include "Cursus.h"

class VisitorCursus {
public:
    VisitorCursus();
    virtual int visit(class Cursus * c) = 0;
    virtual int visit(class CursusAvecListUV * c) = 0;
    virtual int visit(class CursusAvecObli * c) = 0;
    virtual int visit(class CursusTC * c) = 0;
    virtual int visit(class CursusBranche * c) = 0;
};


class VisitorNbCreditCS : public VisitorCursus {
public:
    int visit(class Cursus * c);
    int visit(class CursusAvecListUV * c);
    int visit(class CursusAvecObli * c);
    int visit(class CursusTC * c);
    int visit(class CursusBranche * c);
};

class VisitorNbCreditTM : public VisitorCursus {
public:
    int visit(class Cursus * c);
    int visit(class CursusAvecListUV * c);
    int visit(class CursusAvecObli * c);
    int visit(class CursusTC * c);
    int visit(class CursusBranche * c);
};

class VisitorNbCreditTSH : public VisitorCursus {
public:
    int visit(class Cursus * c);
    int visit(class CursusAvecListUV * c);
    int visit(class CursusAvecObli * c);
    int visit(class CursusTC * c);
    int visit(class CursusBranche * c);
};

class VisitorNbCreditLibre : public VisitorCursus {
public:
    int visit(class Cursus * c);
    int visit(class CursusAvecListUV * c);
    int visit(class CursusAvecObli * c);
    int visit(class CursusTC * c);
    int visit(class CursusBranche * c);
};

class VisitorNbCreditPCB : public VisitorCursus {
public:
    int visit(class Cursus * c);
    int visit(class CursusAvecListUV * c);
    int visit(class CursusAvecObli * c);
    int visit(class CursusTC * c);
    int visit(class CursusBranche * c);
};

class VisitorNbCreditFiliere : public VisitorCursus {
public:
    int visit(class Cursus * c);
    int visit(class CursusAvecListUV * c);
    int visit(class CursusAvecObli * c);
    int visit(class CursusTC * c);
    int visit(class CursusBranche * c);
};

#endif // VISITORCURSUS_H
