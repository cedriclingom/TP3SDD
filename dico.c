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

	  position = 0;

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

      free(pmot);

    }
  else
    {

      printf("Erreur dans la création du dictionnaire!\nBloc lettre non alloué!\n");

      *PcodeCreation = faux;

    }

}


/*------------------------------------------------------------------------------------------------------------------*/
/* LectureFichier          Permet l'ouverture du fichier et la création du dictionnaire des mots lu à partir du     */
/*                         fichier.                                                                                 */
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


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* AffichageDicoParOrdreAlpha              Affichage de tout les mots de dictionnaire en ordre        */
/*                                         alphabetique.                                              */
/*                                                                                                    */
/* En entrée             : pdico         - Pointeur de tete de liste chainée de lettres.              */
/*                                                                                                    */
/* En sortie             :                 Rien en sortie                                             */
/*                                                                                                    */
/* Variable(s) locale(s) : pcour         - l'element courant qui parcourt l'arbre.                    */
/*                         pile          - Pointeur sur la structure de pile contient les adresses    */
/* 					   des lettre parcourues.                                     */
/*                         fin           - un booleen indique la fin du programme                     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/

void AffichageDicoParOrdreAlpha(lettre_t * pdico)
{

	lettre_t * pcour = pdico;

	int nb = 0;

	enum bool fin = faux;				/*initialialisation de notre courant*/
	
	pile_t * pile = InitialisationPile(TAILLE_MAX);	/* l'allocation de la pile*/
	
	if(pile)                                        /* si l'allocation est bien faite*/
	{

	  while(!fin)					/* tant que on est pas arrivé à la fin*/
	    {
	      
	      while(pcour != NULL)			/*tant que le courant est different de NIL*/
		{
		  
		  empiler(pile, pcour);			/* on empile l'adresse de la lettre courante*/
				
		  if(EstMajuscule(pcour))		/*si la lettre est en majuscule*/
		    {
		      
		      AffichageContenuPile(pile);	/* On affiche tous lettre dont les pointeurs sont dans la pile*/

		      ++nb;

		      printf("\n");
					
		    }

		  pcour = pcour->lv;			/* on avance vers le lien vertical*/
				
		}

	      EstVide(pile,&fin);
			
	      if(!fin)		
		{

		  pcour = depiler(pile);
		  
		  pcour = pcour->lh;

		}

	    }

	  LibererPile(&pile);

	  printf("%d\n", nb);

	}
	else
	  {
	    
	    printf("Erreur dans l'allocation de la pile");

	  }

}


/*------------------------------------------------------------------------------------------------------------------*/
/* LectureFichier           Libère le dictionnaire ( qui est une foret).                                            */
/*                                                                                                                  */
/* En entrée             : PpteteListe - Pointeur de pointeur de tete de liste chainée des lettres.                 */
/*                                                                                                                  */
/* En sortie             : PpteteListe - Pointeur de pointeur de tete de liste chainée des lettres.                 */
/*                                                                                                                  */
/* Variable(s) locale(s) : vide        - Pointeur sur une case mémoire contenant vrai si la pile vide et faux sinon.*/
/*                         pile        - Pointeur de structure de pile.                                             */
/*                         pcour       - Pointeur de lettre courante dans la liste chainée de lettres.              */
/*                                                                                                                  */
/*------------------------------------------------------------------------------------------------------------------*/  


void LibererDico(lettre_t ** PpteteListe)
{
  
  enum bool vide;

  pile_t * pile = InitialisationPile(TAILLE_MAX);
  
  lettre_t * pcour = *PpteteListe;

  if(pile)                                             /*si la pile est alloué*/
    {
  
      while(pcour != NULL)                             /*tantque j'ai pas parcouru tout l'arbre*/
	{
	  
	  while(pcour->lv != NULL)                     /*tantqu'il a un lien vertical*/
	    {
	      
	      empiler(pile, pcour);                    /*sauvegarder l'adresse de la lettre courante*/
	      
	      pcour =  pcour->lv;                      /*Mise à jour du courant*/
	      
	    }
	  
	  SuppressionLettre(&pcour);
	  
	  EstVide(pile, &vide);
	  
	  while( !pcour && !vide)                      /*tantqu'on a aucune lettre courante et la pile est non vide*/
	    {
	      
	      pcour = depiler(pile);
	      
	      SuppressionLettre(&pcour);

	      EstVide(pile, &vide);
	      
	    }
	  
	}
      
      LibererPile(&pile);
      
    }
  
}
