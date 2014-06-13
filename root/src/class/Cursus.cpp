#include "Cursus.h"

/* Debut Cursus */

bool Cursus::remplireCursus(){
    return false;
}

void Cursus::accept(class Visitor &v){
}

Cursus::~Cursus(){

}

/* Fin Cursus */
/* Debut CursusAvecObli */

bool CursusAvecObli::remplireCursus() {
    return false;
}

void CursusAvecObli::accept(class VisitorCursus &v){

}

CursusAvecObli::~CursusAvecObli(){

}

/* Fin CursusAvecObli */
/* Debut CursusAvecListUV */

CursusAvecListUV::~CursusAvecListUV(){

}

bool CursusAvecListUV::remplireCursus(){
    return false;
}

void CursusAvecListUV::accept(class VisitorCursus &v){

}

/* Fin CursusAvecListUV */
/* Debut CursusBranche */

CursusBranche::~CursusBranche() {

}
bool CursusBranche::remplireCursus(){
    return false;
}

/* Fin CursusAvecListUV */
/* Debut CursusTC */

CursusTC::~CursusTC() {

}
bool CursusTC::remplireCursus(){
    return false;
}

/* Fin CursusTC */
