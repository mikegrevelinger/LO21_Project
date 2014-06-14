#include "VisitorCursus.h"

VisitorCursus::VisitorCursus()
{
}

int VisitorNbCreditCS::visit(class Cursus * c) {
    return 0;
}

int VisitorNbCreditCS::visit(class CursusAvecListUV * c) {
    return 0;
}

int VisitorNbCreditCS::visit(class CursusAvecObli * c) {
    return 0;
}

int VisitorNbCreditCS::visit(class CursusTC * c) {
    return c->getNbCreditsCS();
}

int VisitorNbCreditCS::visit(class CursusBranche * c) {
    return c->getNbCreditsCS();
}




int VisitorNbCreditTM::visit(class Cursus * c) {
    return 0;
}

int VisitorNbCreditTM::visit(class CursusAvecListUV * c) {
    return 0;
}

int VisitorNbCreditTM::visit(class CursusAvecObli * c) {
    return 0;
}

int VisitorNbCreditTM::visit(class CursusTC * c) {
    return c->getNbCreditsTM();
}

int VisitorNbCreditTM::visit(class CursusBranche * c) {
    return c->getNbCreditsTM();
}




int VisitorNbCreditTSH::visit(class Cursus * c) {
    return 0;
}

int VisitorNbCreditTSH::visit(class CursusAvecListUV * c) {
    return 0;
}

int VisitorNbCreditTSH::visit(class CursusAvecObli * c) {
    return 0;
}

int VisitorNbCreditTSH::visit(class CursusTC * c) {
    return c->getNbCreditsTSH();
}

int VisitorNbCreditTSH::visit(class CursusBranche * c) {
    return c->getNbCreditsTSH();
}




int VisitorNbCreditLibre::visit(class Cursus * c) {
    return 0;
}

int VisitorNbCreditLibre::visit(class CursusAvecListUV * c) {
    return 0;
}

int VisitorNbCreditLibre::visit(class CursusAvecObli * c) {
    return 0;
}

int VisitorNbCreditLibre::visit(class CursusTC * c) {
    return c->getNbCreditsLibre();
}

int VisitorNbCreditLibre::visit(class CursusBranche * c) {
    return c->getNbCreditsLibre();
}



int VisitorNbCreditPCB::visit(class Cursus * c) {
    return 0;
}

int VisitorNbCreditPCB::visit(class CursusAvecListUV * c) {
    return 0;
}

int VisitorNbCreditPCB::visit(class CursusAvecObli * c) {
    return 0;
}

int VisitorNbCreditPCB::visit(class CursusTC * c) {
    return 0;
}

int VisitorNbCreditPCB::visit(class CursusBranche * c) {
    return c->getNbCreditsPCB();
}



int VisitorNbCreditFiliere::visit(class Cursus * c) {
    return 0;
}

int VisitorNbCreditFiliere::visit(class CursusAvecListUV * c) {
    return 0;
}

int VisitorNbCreditFiliere::visit(class CursusAvecObli * c) {
    return 0;
}

int VisitorNbCreditFiliere::visit(class CursusTC * c) {
    return 0;
}

int VisitorNbCreditFiliere::visit(class CursusBranche * c) {
    return c->getNbCreditsPSF();
}
