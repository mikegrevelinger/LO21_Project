#include "Prevision.h"


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
       if(PrevisionTC::isObligatoireUv(ListUV[i]))
       {
            res->push_front(ListUV[i][0]);
       }
   }
   /////////////// trie des UV Voulues/Neutre/Rejetées /////////////////////////////////
    for(int j=0;j<ListUV.size();j++)
    {
           if(dbm.getChoix(ListUV[j][0],id)==enumeration::VEUT && !PrevisionTC::isObligatoireUv(ListUV[j])) // Si l'etudiant veut cette uv, on la met derriere les uvs obligatoire
           {
           res->push_back(ListUV[j][0]);
           }
           else if(dbm.getChoix(ListUV[j][0],id)==enumeration::REJ && !PrevisionTC::isObligatoireUv(ListUV[j])) // Si l'étudiant ne veut pas cette uv, on la met à la fin de notre liste temporaire
           {
               temp->push_back(ListUV[j][0]);
           }
           else
           {
             temp->push_front(ListUV[j][0]); // Si l'uv est " neutre ", elle est mise au début de la liste temporaire.
           }
   }

   ///////// Liste finale ( Composition de res + temp ) /////////

  *res=*res+*temp; // fussionner les deux listes.


   return *res;
}

/*
void Prevision::prevision(const QString cursus,const int id){

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
