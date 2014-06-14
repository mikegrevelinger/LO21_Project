#include "Prevision.h"

/*
PrevisionTC::PrevisionTC(const int idEtu, const QString& nom) {
    CursusFactory c;
    Cursus * cur = c.makeCursus(idEtu);
    cur->remplireCursus(nom);
}

QList<QString>  PrevisionTC::NewList(Cursus& cur, const int &id){
   QList<QString> *res = new QList<QString>;
   QList<QString> *temp = new QList<QString>;
   DBManager & dbm = DBManager::getInstance();
   QList<QStringList> ListUV = cur.getListUV();

   ////////////////////////////Dans un premier temps, on met en first position les UVS Obligatoire du Cursus /////////////////////
   for(int i=0;i<ListUV.size();i++)
   {
       if(PrevisionTC::isObligatoireUv(ListUV[i]) && !dbm.isUVInscrit(ListUV[i].at(0),id))
       {
            res->push_front(ListUV[i][0]);
       }
   }
   /////////////// trie des UV Voulues/Neutre/Rejetées /////////////////////////////////
    for(int j=0;j<ListUV.size();j++)
    {
           if(dbm.getChoix(ListUV[j][0],id)==enumeration::VEUT && !PrevisionTC::isObligatoireUv(ListUV[j]) && !dbm.isUVInscrit(ListUV[j].at(0),id)) // Si l'etudiant veut cette uv, on la met derriere les uvs obligatoire
           {
           res->push_back(ListUV[j][0]);
           }
           else if(dbm.getChoix(ListUV[j][0],id)==enumeration::REJ && !PrevisionTC::isObligatoireUv(ListUV[j]) && !dbm.isUVInscrit(ListUV[j].at(0),id)) // Si l'étudiant ne veut pas cette uv, on la met à la fin de notre liste temporaire
           {
               temp->push_back(ListUV[j][0]);
           }
           else if(!dbm.isUVInscrit(ListUV[j].at(0),id) && !PrevisionTC::isObligatoireUv(ListUV[j]))
           {
             temp->push_front(ListUV[j][0]); // Si l'uv est " neutre ", elle est mise au début de la liste temporaire.
           }
   }

   ///////// Liste finale ( Composition de res + temp ) /////////

  *res=*res+*temp; // fussionner les deux listes.


   return *res;
}


void PrevisionTC::prevision(Cursus& cur,const int id){

   QList<QString> UV;
   QList<QString> UValide; // liste qui sera valide par l'étudiant
   UV=PrevisionTC::NewList(cur,id);
   DBManager & dbm = DBManager::getInstance();

   int i,j;
   i=0;
   QString NomCursus=cur.getNom();
   int NbCreditActuelTot=dbm.getCreditsTotalEtu(NomCursus); // A voir pour récuperer le nombre de Credit actuel validé.
   enumeration::Saison semestreActuel;
   semestreActuel=dbm.getSemestreActuel(id); //Pour avoir le semestre actuel ( Primptemps/Automne)
   int semestreActuelETU;
   semestreActuelETU=dbm.getSemestreActuelETU(id);
   int nbCreditCS,nbCreditTM,nbCreditTSH;
   nbCreditCS=dbm.getCreditsCategorie(id,enumeration::CS);
   nbCreditTM=dbm.getCreditsCategorie(id,enumeration::TM);
   nbCreditTSH=dbm.getCreditsCategorie(id,enumeration::TSH);
// unsigned int getCreditsCategorie(const int id,enumeration::CategorieUV c);
   int NombreCreditCeSemestre=0;
   int NombreUVSemestre=0;
   int annee;
   annee=dbm.getAnneeActuelETU(id);

   enumeration::Saison semestre; // Permet de savoir si on est en Automne ou primptemps.
   semestre=semestreActuel;
   if(semestre==enumeration::Automne)
       semestre=enumeration::Printemps;
   else
   {
       semestre=enumeration::Automne;
       annee++;
   }

   while(i<UV.size() && NbCreditCursus=DBManager::getCreditCursus(cursus)>NbCreditActuelTot)
   {
       if(semestreActuelETU<6) // On part du principe que la personne peut faire 2 semestre en plus, à partir de là, elle sera renvoyée//
       {
           if(NombreUVSemestre<7 && NombreCreditCeSemestre<31) // Pour faire l'alternance des semestres; Cependant, il pourra avoir plus de 31 ce semestre.
           {
               if( PrevisionTC::benefique(UV[i],nbCreditCS,nbCreditTM,nbCreditTSH) && dbm.isEnseigne(UV,semestre)) // Si l'uv améliore notre profil et qu'elle est enseignee ce semestre
               {
                   UValide.push_back(UV[i]); // Rajout de l'uv à la liste des uvs pseudo valide
                   enumeration::CategorieUV categorie;
                   categorie=dbm.getCategorieUV(UV[i]); // Rajout des crédits de l'uv.
                   int credit=dbm.getCreditsUV(UV[i]);
                   if(categorie==enumeration::CS)
                   {
                       nbCreditCS= nbCreditCS + credit;
                       NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                   }
                   if(categorie==enumeration::TM)
                   {
                       nbCreditTM= nbCreditTM + credit;
                       NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                   }
                   if(categorie==enumeration::TSH)
                   {
                       nbCreditTSH= nbCreditTSH + credit;
                       NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                   }
                   NombreUVSemestre++;
               }
           }
           else
           { // faire new Liste
               if(true)//validation==0) // C'est à dire s'il est d'accord ? On recommence tout, Uv en rejetee
               {// il faut qu'il valide tout ses uvs, c'est à dire, il ne rejette pas d'uv proposé
   //////////////////////////////// validation ////////////////////////////
                   for(j=0;j<NombreUVSemestre;j++)
                   {
                   dbm.inscriptionUValide(id,UValide[j],annee,semestre);// On met les Notes des UVS à INSCRIT et le semestre et l'annee ou il compte le faire
                   }
                   UValide.clear(); // On remet sa liste valide à 0 pour le prochain semestre.
                   if(semestre==enumeration::Automne) // On fait l'alternance des semestres
                      semestre=enumeration::Printemps;
                   else
                   {
                      semestre=enumeration::Automne;
                      annee++;
                   }
                   UV=PrevisionTC::NewList(cur,id); // on fait la nouvelle liste.
                   i=0; // On remet le " compteur de la liste uv " à 0;
                   NombreUVSemestre=0; // On remet le compteur UV et Credit à 0 car new semestre
                   NombreCreditCeSemestre=0;
                   semestreActuelETU++;
                   if( PrevisionTC::benefique(UV[i],nbCreditCS,nbCreditTM,nbCreditTSH) && dbm.isEnseigne(UV,semestre))
                   {
                       UValide.push_back(UV[i]); // Rajout de l'uv à la liste des uvs pseudo valide
                       enumeration::CategorieUV categorie;
                       categorie=dbm.getCategorieUV(UV[i]); // Rajout des crédits de l'uv.
                       int credit=dbm.getCreditsUV(UV[i]);
                       if(categorie==enumeration::CS)
                       {
                           nbCreditCS= nbCreditCS + credit;
                           NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                       }
                       if(categorie==enumeration::TM)
                       {
                           nbCreditTM= nbCreditTM + credit;
                           NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                       }
                       if(categorie==enumeration::TSH)
                       {
                           nbCreditTSH= nbCreditTSH + credit;
                           NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                       }
                       NombreUVSemestre++;
                   }
               }
               else // S'il ne valide pas, il recommence l'algorithme en ayant pris en compte dans la fonction validé les uvs qu'ils rejettent.
               {
                  NombreCreditCeSemestre=0;
                  NombreUVSemestre=0;
                  i=0;
               }
           }
   }
       i++; // On incrémente le nombre d'uv parcourue dans la liste d'uv
   }
}



/*
void PrevisionTC::prevision(const QString cursus,const int id){

   QList<QString> UV=new QList<QString>;
   QList<QString> UValide= new QList<QString>; // liste qui sera valide par l'étudiant
   UV=Prevision::NewList(cursus); // a revoir

   int j;
   int NbCreditActuelTot=DBManager::getCreditTotalEtu(cursus); // A voir pour récuperer le nombre de Credit actuel validé.
   int semestreActuel;
   semestreActuel=DBManager::getSemestreActuel(id); //Pour avoir le semestre actuel de etudiant
   int nbCreditCS,nbCreditTM,nbCreditTSH,NbCreditPCBETU,NbCreditPSFETU;
   nbCreditCS=DBManager::getCreditsCSEtu(id);
   nbCreditTM=DBManager::getCreditsTMEtu(id);
   nbCreditTSH=DBManager::getCreditsTSHEtu(id);
   bool Branche;
   Branche=isTypeBranche(cursus);
   //////////////////////////////// il faut le getCreditPCB propre au Cursus branche.
   if(branche)
   {
       NbCreditPCBETU=DBManager::getCreditsPCBETU(id);
       NbCreditPSFETU=DBManager::getCreditsPSFETU(id);
       NbCreditPCB=DBManager::getCreditsPCB(id);
       NbCreditPSF=DBManager::getCreditsPSF(id);
   }

   int NombreCreditCeSemestre=0;
   int NombreUVSemestre=0;
   int annee;
   annee=DBManager::getAnnee(id);

   QString semestre; // Permet de savoir si on est en Automne ou primptemps.
   semestre=cursus::getSemestre;
   if(semestre=='Automne')
       semestre='Primtemps';
   else
       semestre='Automne';

   while(i<UV.size() && NbCreditCursus=CursusManager::getCreditCursus(cursus)>NbCreditActuelTot)
   {
       if(semetreActuel<6) // On part du principe que la personne peut faire 2 semestre en plus, à partir de là, elle sera renvoyée//
       {
           if(NombreUVSemestre<7 && NombreCreditCeSemestre<31) // Pour faire l'alternance des semestres; Cependant, il pourra avoir plus de 31 ce semestre.
           {
               if( benefique(UV[i],NbCreditCS,NbCreditTM,NbCreditTSH) && DBManager::isEnseigne(UV,semestre)) // Si l'uv améliore notre profil et qu'elle est enseignee ce semestre
               {
                   UValide.push_back(UV[i]); // Rajout de l'uv à la liste des uvs pseudo valide

                   categorie=DBManager::getCategorie(UV[i]); // Rajout des crédits de l'uv.
                   int credit=DBManager::getCredit(UV[i]);
                   if(categorie=='CS')
                   {
                       NbCreditCs= NbCreditCs + credit;
                       NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                   }
                   if(categorie=='TM')
                   {
                       NbCreditTM= NbCreditTM + credit;
                       NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                   }
                   if(categorie=='TSH')
                   {
                       NbCreditTSH= NbCreditTSH + credit;
                       NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                   }
                   NombreUVSemestre++;
               }
           }
           else
           { // faire new Liste
               if(validation==0) // C'est à dire s'il est d'accord ?
               {// il faut qu'il valide tout ses uvs, c'est à dire, il ne rejette pas d'uv proposé
   //////////////////////////////// validation ////////////////////////////
                   for(j=0;j<NbUVSemestre;j++)
                   {
                   DBManager::InscriptionUValide(id,UVValide[j],annee,semestre);// On met les Notes des UVS à INSCRIT et le semestre et l'annee ou il compte le faire
                   }
                   UValide.clear(); // On remet sa liste valide à 0 pour le prochain semestre.
                   if(semestre=='Automne') // On fait l'alternance des semestres
                      semestre='Primtemps';
                   else
                   {
                      semestre='Automne';
                      annee++;
                   }
                   UV=DBManager::NewList(cursus); // on fait la nouvelle liste.
                   i=0; // On remet le " compteur de la liste uv " à 0;
                   NombreUVSemestre=0; // On remet le compteur UV et Credit à 0 car new semestre
                   NombreCreditCeSemestre=0;
                   semestreActuel++;
                   if( benefique(UV[i],NbCreditCS,NbCreditTM,NbCreditTSH))
                   {
                       UValide.push_back(UV[i]); // Rajout de l'uv à la liste des uvs pseudo valide
                       categorie=DBManager::getCategorie(UV[i]); // Rajout des crédits de l'uv.
                       int credit=DBManager::getCredit(UV[i]);
                       if(categorie=='CS')
                       {
                           NbCreditCs= NbCreditCs + credit;
                           NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                       }
                       if(categorie=='TM')
                       {
                           NbCreditTM= NbCreditTM + credit;
                           NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                       }
                       if(categorie=='TSH')
                       {
                           NbCreditTSH= NbCreditTSH + credit;
                           NombreCreditCeSemestre= NombreCreditCeSemestre + credit;
                       }
                       if(Branche)
                       {
                           if(NbCreditPCBETU<NbCreditPCB)
                           NbCreditPCBETU=NbCreditPCBETU + credit;
                           if(NbCreditPSFETU<NbCreditPSF)
                               NbCreditPSFETU=NbCreditPSFETU + credit;
                       }
                       NombreUVSemestre++;
                   }
               }
               else // S'il ne valide pas, il recommence l'algorithme en ayant pris en compte dans la fonction validé les uvs qu'ils rejettent.
               {
                  NombreCreditCeSemestre=0;
                  NombreUVSemestre=0;
                  i=0;
               }
           }
   }
       i++; // On incrémente le nombre d'uv parcourue dans la liste d'uv
   }
}
*/
/*
bool PrevisionTC::isObligatoireUv(QStringList &ListUV)
{
    foreach (const QString &str,ListUV) {
        if(str.contains("Obligatoire"))
        {
            return true;
        }
    }
        return false;

}

bool PrevisionTC::benefique(const QString &UV,const int &nbCreditCSActuel,const int &nbCreditTMActuel,const int &nbCreditTSHActuel,const QString &cursus)
{
   enumeration::CategorieUV categorie;
    // enumeration::CategorieUV getCategorieUV(const QString & nom);
   categorie=DBManager::getCategorieUV(UV);
   int creditCS, creditTSH, creditTM;
   if(categorie==enumeration::CS)
   {
       if(nbCreditCSActuel<creditCS=cursus::getCreditCS(cursus)) //// c'est le que ça va plus
       {
           return true;
       }
       else
       {
           return false;
       }
   }
   if(categorie==enumeration::TM)
   {
       if(nbCreditTMActuel<creditTM=cursus::getCreditTM(cursus))
       {
           return true;
       }
       else
       {
           return false;
       }
   }
   if(categorie==enumeration::TSH)
   {
       if(nbCreditTSHActuel<creditTSH=cursus::getCreditTSH(cursus))
       {
           return true;
       }
       else
       {
           return false;
       }
   }
}
*/
