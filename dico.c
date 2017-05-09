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

  lettre_t ** prec = PpteteListe;

  while(((pmot[*position] != '\n') && (pmot[*position] != '\0')) && (trouver))/*tantqu'on est pas à la fin du mot et qu'on trouve que la lettre précédent du mot existe déjà */
    {

      prec = RechercherPrec(prec, pmot[*position], &trouver);/* Recherche la lettre courante du mot dans la liste chainée courante*/ 

      if(trouver)                                                     /*si on a trouvé la lettre courante*/
	{

	  (*position)++;                                                  /*on avance dans le mot*/

	  if((pmot[*position] != '\n') || (pmot[*position] != '\n'))                                   /*si on est pas à la fin du mot*/
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

  *PcodeInsertion = vrai;                          /*on suppose que l'insertion du mot va bien se passé*/

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

  if(EstMiniscule(*ppcar))
    {

      EnMajuscule(*ppcar);
      
    }

}



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
/* AffichageDico               Affichage de tout les mots de dictionnaire en ordre alphabetique.      */
/*                                                                                                    */
/* En entrée             : pdico         - Pointeur de tete de liste chainée de lettres.              */
/*                         pmotif        - Pointeur sur une chaine de caractères.                     */
/*                                                                                                    */
/* En sortie             :                 Rien en sortie                                             */
/*                                                                                                    */
/* Variable(s) locale(s) : pcour         - L'element courant qui parcourt l'arbre.                    */
/*                         pile          - Pointeur sur la structure de pile contient les adresses    */
/* 					   des lettre parcourues.                                     */
/*                         fin           - Un booleen indique la fin du programme                     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


void AffichageDicoAvecMotif(lettre_t * pdico, char * pmotif)
{

  lettre_t * pcour = pdico;
  
  enum bool fin = faux;				/*initialialisation de notre courant*/
  
  pile_t * pile = InitialisationPile(TAILLE_MAX);	/* l'allocation de la pile*/
  
  if(pile)                                        /* si l'allocation est bien faite*/
    {

      while(!fin)					/* tant que on est pas arrivé à la fin*/
	{
	      
	  while(pcour != NULL)			/*tant que le courant est different de NIL*/
	    {
	      
	      empiler(pile, pcour);			/* on empile l'adresse de la lettre courante*/
	      
	      if(EstMajuscule(pcour))		        /*si la lettre est en majuscule*/
		{
		  
		  AffichageContenuPile(pmotif, pile);	/* On affiche tous lettre dont les pointeurs sont dans la pile*/
		  
		  printf("\n");
		  
		}
	      
	      pcour = pcour->lv;			/* on avance vers le lien vertical*/
	      
	    }
	  
	  EstVide(pile,&fin);
	  
	  if(!fin)                                     /*si la pile n'est pas vide*/		
	    {
	      
	      pcour = depiler(pile);
	      
	      pcour = pcour->lh;
	      
	    }
	  
	}
      
      LibererPile(&pile);
      
    }
  else
    {
      
      printf("Erreur dans l'allocation de la pile");
      
    }
  
}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* AffichageDico               Affichage de tout les mots de dictionnaire en ordre alphabetique.      */
/*                                                                                                    */
/* En entrée             : pdico         - Pointeur de tete de liste chainée de lettres.              */
/*                                                                                                    */
/* En sortie             :                 Rien en sortie                                             */
/*                                                                                                    */
/* Variable(s) locale(s) :                 Rien en variable locale.                                   */
/*----------------------------------------------------------------------------------------------------*/

void AffichageDico(lettre_t * pdico)
{

  AffichageDicoAvecMotif(pdico, NULL);

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


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* RechercheMotif               Recherche un motif et affiche les mots qui commencent par ce motif.   */
/*                                                                                                    */
/* En entrée             : pdico         - Pointeur de tete de liste chainée de lettres.              */
/*                         pmotif        - Pointeur sur une chaine de caractères.                     */
/*                                                                                                    */
/* En sortie             :                 Rien en sortie                                             */
/*                                                                                                    */
/* Variable(s) locale(s) : position      - La position courante dans le motif.                        */
/*                         prec          - Pointeur de pointeur sur un bloc contenant une lettre.     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



void RechercheMotif(lettre_t * pdico, char * pmotif)
{

  int position = 0;

  lettre_t ** prec = RechercheDivergence(pmotif, &position, &pdico);       /*Cherche si le motif existe*/

  if(pmotif[position] == '\0')                                             /*si le motif existe*/
    {

      AffichageDicoAvecMotif(*prec, pmotif);                               /*Affiche les mots qui commencent par le motif*/

    }
  else
    {

      printf("Le motif n'existe pas!\n");

    }

}



/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* RechercheDico             Lit un motif qui sera rechercher dans le dictionnaire.                   */
/*                                                                                                    */
/* En entrée             : pdico         - Pointeur de tete de liste chainée de lettres.              */
/*                                                                                                    */
/* En sortie             :                 Rien en sortie                                             */
/*                                                                                                    */
/* Variable(s) locale(s) : CodeLecture   - Variable contenant vrai si la lecture du motif c'est bien  */
/*                                         passé et faux sinon.                                       */
/*                         pmotif        - Pointeur sur une chaine de caractères.                     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



void RechercheDico(lettre_t * pdico)
{

  enum bool CodeLecture;
  
  char * pmotif = (char *)malloc(TAILLEMOT * sizeof(char));
  
  if(pmotif)                                                    /*si l'allocation du motif réussi*/
    {
      
      printf("Veuillez entrer le motif à rechercher\n");
      
      CodeLecture = scanf("%s", pmotif);
      
      if(CodeLecture)                                           /*si lecture du motif bien passé*/
	{
	  
	  RechercheMotif(pdico, pmotif);
	  
	}
      
      free(pmotif);
      
    }
  else
    {
      
      printf("Erreur d'allocation du motif.\n");
      
    }
  
}
