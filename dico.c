/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/*                                               dico.c                                               */
/*                                                                                                    */
/* Role : Définition des procédures et fonctions permettant la gestion du dictionnaire.               */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/







#include "./dico.h"







/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* CreerDico           Création du dictionnaire.                                                      */
/*                                                                                                    */
/* En entrée             : PpteteListe   - Pointeur de pointeur de tete de liste chainée de lettres.  */
/*                         f             - Pointeur sur un fichier.                                   */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la création */
/*                                         du dictionnaire c'est bien passé et faux sinon.            */
/*                                                                                                    */
/* En sortie             : PpteteListe   - Pointeur de pointeur de tete de liste chainée de lettres.  */
/*                         PcodeCreation - Pointeur sur la case mémoire contenant vrai si la création */
/*                                         du dictionnaire c'est bien passé et faux sinon.            */
/*                                                                                                    */
/* Variable(s) locale(s) : position      - Position courante dans le mot c'est-à-dire l'indice.       */
/*                         CodeLecture   - Case mémoire contenant faux si on a atteint la fin du      */
/*                                         fichier et vrai sinon.                                     */
/*                         CodeInsertion - Case mémoire contenant vrai si l'insertion d'un mot c'est  */
/*                                         bien passé et faux sinon.                                  */
/*                         pmot          - Pointeur sur le mot (chaine de caractères).                */
/*                         prec          - Pointeur de pointeur de tete de liste chainée de lettre ou */
/*                                         pointeur de la case pointeur de l'élément précédent de la  */
/*                                         liste chainée des lettres.                                 */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



void CreerDico(lettre_t ** PpteteListe, FILE * f,enum bool * PcodeCreation)
{

  int position = 0;

  enum bool CodeLecture = vrai, CodeInsertion = vrai;
  
  char * pmot = (char *)malloc(TAILLEMOT * sizeof(char));

  lettre_t ** prec = NULL;

  *PcodeCreation = vrai;                                            /*on suppose que la création va bien se passé*/

  if(pmot != NULL)                                                  /*si l'allocation c'est bien passé*/
    {

      LectureMot(f, pmot, &CodeLecture);

      while(CodeLecture && CodeInsertion)                           /*tantque la lecture continue et l'insertion se passe bien*/
	{

	  prec = RechercheDivergence(pmot, &position, PpteteListe);

	  InsertionMot(pmot, &position, prec, &CodeInsertion);

	  if(CodeInsertion)                                         /*si l'insertion se passe bien*/
	    {

	      LectureMot(f, pmot, &CodeLecture);

	    }

	}

      if(!CodeInsertion)
	{

	  printf("Erreur d'insertion d'un mot dans le dictionnaire.!\n");
	  
	  *PcodeCreation = faux;

	}

    }
  else
    {

      printf("Erreur dans la création du dictionnaire!\nBloc lettre non alloué!\n");

      *PcodeCreation = faux;

    }

}


/*------------------------------------------------------------------------------------------------------------------*/
/* LectureFichier           Lire chaque ligne de notre fichier qui contient comme données année, semaine, jour,     */
/*                          heure et créer une liste chainée à deux niveaux à partir de cette lecture.              */
/*                                                                                                                  */
/* En entrée:     NomFichier - Nom du fichier dans le quel on va lire.                                              */
/*               PpteteListe - Pointeur de pointeur de tete de liste chainée des semaines.                          */
/*              PcodeLecture - Pointeur sur la case contenant le code de lecture vrai si la lecture c'est           */
/*                             bien passé et faux sinon.                                                            */
/*                                                                                                                  */
/* En sortie:    PpteteListe - Pointeur de pointeur de tete de liste chainée des semaines.                          */
/*              PcodeLecture - Pointeur sur la case contenant le code de lecture vrai si la lecture c'est           */
/*                             bien passé et faux sinon.                                                            */
/*                                                                                                                  */
/* Variable(s) locale(s):  f - Pointeur sur le fichier.                                                             */
/*------------------------------------------------------------------------------------------------------------------*/  

   
void LectureFichier(char * NomFichier, lettre_t ** PpteteListe, enum bool * PcodeLecture)
{

  FILE * f = NULL;

  *PcodeLecture = vrai;                                      /*on suppose que la lecture va bien se passée*/

  f = fopen(NomFichier,"r");

  if (f != NULL)                                             /*si le fichier est ouvert*/
    {

      CreerDico(PpteteListe, f, PcodeLecture);               /*Crée un dictionnaire*/

      fclose(f);

    }
  else                                                       /*Si la lecture ne s'est pas bien passé*/
    {

      *PcodeLecture = faux; 

      printf("Erreur d'ouverture du fichier!\n");
                                  
    }

}


