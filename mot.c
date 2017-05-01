/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/*                                             mot.c                                                  */
/*                                                                                                    */
/* Role : Définition des procédures et fonctions permettant la gestion des mots.                      */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



#include "./mot.h"






/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* LectureMot              Lit un mot à partir d'un fichier.                                          */
/*                                                                                                    */
/* En entrée             : f            - Pointeur sur un fichier.                                    */
/*                         pmot         - Pointeur sur une chaine de caractères qui est un mot.       */
/*                         PcodeLecture - Pointeur sur une case mémoire contenant une valeur 1 si la  */
/*                                        lecture c'est bien passée et 0 sinon.                       */
/*                                                                                                    */
/* En sortie             : pmot         - Pointeur sur une chaine de caractères qui est un mot.       */
/*                         PcodeLecture - Pointeur sur une case mémoire contenant une valeur 1 si la  */
/*                                        lecture c'est bien passée et 0 sinon.                       */
/*                                                                                                    */
/* Variable(s) locale(s) :                Rien comme variable loacle.                                 */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


void LectureMot(FILE * f, char * pmot, enum bool * PcodeLecture)
{

  if(fgets(pmot, TAILLEMOT, f)) /*si un mot existe dans le fichier et que la lecture c'est bien passé*/
    {

      *PcodeLecture = vrai;       

    }
  else
    {

      *PcodeLecture = faux;

    }

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* RechercheDivergence           Recherche et renvoie l'adresse de la case pointeur de la lettre après*/
/*                               la quelle on doit insérer.                                           */
/*                                                                                                    */
/* En entrée             : pmot        - Pointeur sur le mot à insérer dans le dictionnaire.          */
/*                         position    - L'indice de la lettre courante dans le mot.                  */
/*                         PpteteListe - Pointeur de pointeur de liste chainées de lettres.           */                        
/*                                                                                                    */
/* En sortie :             position    - L'indice de la lettre courante dans le mot.                  */
/*                         PpteteListe - Pointeur de pointeur de liste chainées de lettres.           */
/*                                                                                                    */
/* Variable(s) locale(s) : prec        - Pointeur de pointeur de tete de liste chainée de lettres ou  */
/*                                       pointeur sur la case pointeur de l'élément précédent de la   */
/*                                       liste chainée de lettres.                                    */
/*                         trouver     - Case mémoire contenant vrai si la lettre est trouver et faux */
/*                                       sinon.                                                       */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



lettre_t ** RechercheDivergence(char * pmot, int * position, lettre_t ** PpteteListe)
{

  enum bool trouver = vrai;

  lettre_t ** prec = NULL;

  while((pmot[*position] != '\n') && (trouver))/*tantqu'on est pas à la fin du mot et qu'on trouve que la lettre précédent du mot existe déjà */
    {

      prec = RechercherPrec(PpteteListe, pmot[*position], &trouver);/* Recherche la lettre courante du mot dans la liste chainée courante*/ 

      if(trouver)                                                     /*si on a trouvé la lettre courante*/
	{

	  (*position)++;                                                  /*on avance dans le mot*/

	  if(pmot[*position] != '\n')                                   /*si on est pas à la fin du mot*/
	    {

	      prec = &((*prec)->lv);                        /*On va vers le lien vertical*/

	    }

	}

    }

  return prec;

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* InsertionMot            Insère un mot dans le dictionnaire.                                        */
/*                                                                                                    */
/* En entrée             : pmot           - Pointeur sur le mot à insérer dans le dictionnaire.       */
/*                         position       - Pointeur sur la case mémoire contenant la position        */
/*                                          courante dans le mot.                                     */
/*                         ppcar          - Pointeur de pointeur de tete de liste chainée des lettres */
/*                                          ou pointeur sur la case pointeur de l'élément précédent   */
/*                                          de liste chainée de lettres.                              */
/*                         PcodeInsertion - Pointeur sur la case mémoire contenant vrai si l'insertion*/
/*                                          c'est bien passée et faux sinon.                          */
/*                                                                                                    */
/* En sortie             : position       - Pointeur sur la case mémoire contenant la position        */
/*                                          courante dans le mot.                                     */
/*                         PcodeInsertion - Pointeur sur la case mémoire contenant vrai si l'insertion*/
/*                                          c'est bien passée et faux sinon.                          */             
/*                                                                                                    */
/* Variable(s) locale(s) : pcar           - Pointeur sur le bloc devant contenir une lettre du mot.   */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



void InsertionMot(char * pmot, int * position, lettre_t ** ppcar, enum bool * PcodeInsertion)
{

  lettre_t * pcar = NULL;

  *PcodeInsertion = vrai;                            /*on suppose que l'insertion du mot va bien se passé*/

  while(pmot[*position] != '\n')                   /*si on est pas à la fin du mot à insérer*/
    {

      pcar = AllocationLettre();

      if(pcar != NULL)                             /*si le bloc lettre est alloué*/
	{

	  pcar->valeur = pmot[*position];          /*insérer la lettre dans le bloc*/

	  InsertionLettre(ppcar, pcar);            /*insère le bloc dans la liste chainée courante de lettres*/

	  (*position)++;                             /*on avance dans le mot*/

	  if(pmot[*position] != '\n')              /*si on n'est pas à la fin du mot*/
	    {

	      ppcar = &((*ppcar)->lv);             /*on fait la mise à jour du pointeur precedent*/

	    }
	  
	}
      else
	{

	  *PcodeInsertion = faux;

	}

    }

  EnMajuscule(*ppcar);

}
