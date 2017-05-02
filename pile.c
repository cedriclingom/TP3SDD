/*----------------------------------------------------------------------------------------------------*/
/*                                              pile.c                                                */
/*                                                                                                    */
/* Role : Définitions des fonctions et procédures permettant la gestion des piles.                    */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/








#include "./pile.h"








/*----------------------------------------------------------------------------------------------------*/
/* InitialisationPile          Alloue une structure pile ainsi que le tableau servant de pile.        */
/*                                                                                                    */
/* En entrée :       TaillePile - Elle représente la taille de la taille.                             */
/*                                                                                                    */
/* En sortie :       Renvoie l'adresse de la structure de pile.                                       */
/*                                                                                                    */
/* Variable(s) locale(s) :     pile - Pointeur sur la structure de pile.                              */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



pile_t * InitialisationPile (int TaillePile)
{

	pile_t * pile = (pile_t *)malloc(sizeof(pile_t));

	if(pile != NULL)	                                                /* si l'allocation est reussite*/
	{
		pile->taille = TaillePile;				        /*fixer la taille de la pile*/

		pile->NumeroSommet = -1;

		pile->tab = (objet_t *)malloc(TaillePile * sizeof(objet_t));	/* allouer un tableau de donnees de taille TaillePile */

		if(pile->tab == NULL)						/* si l'allocation de tab est echouée*/
		  {
		    
		    free(pile);							/* on libere la Pile */

		    pile = NULL;

		  }
	}

	return pile;
}		
		

		





/*----------------------------------------------------------------------------------------------------*/
/* EstPleine        Vérifie si notre pile est pleine.                                                 */
/*                                                                                                    */
/* En entrée :      pile - Pointeur sur la structure de pile.                                         */
/*                pleine - Pointeur sur la case mémoire contenant vrai ou faux, pour dire comme quoi  */
/*                         la pile est respectivement pleine ou pas.                                  */
/*                                                                                                    */
/* En sortie :    pleine - Pointeur sur la case mémoire contenant vrai ou faux, pour dire comme quoi  */
/*                         la pile est respectivement pleine ou pas.                                  */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


		
void EstPleine(pile_t * pile, enum BOOL * pleine) 
{
  
  *pleine = vrai;                                        /*suposons qu'elle est pleine*/

  if(pile->NumeroSommet < ((pile->taille)-1))	         /*si la pile n'est pas pleine */
    {
      *pleine = faux;

    }

}







/*----------------------------------------------------------------------------------------------------*/
/* empiler        Empile une valeur dans la pile (Ajoute une valeur au sommet de la pile).            */
/*                                                                                                    */
/* En entrée :    pile - Pointeur sur la structure de pile.                                           */
/*                 val - La valeur à empiler.                                                         */
/*                                                                                                    */
/* En sortie :    Rien en sortie.                                                                     */
/*                                                                                                    */                 
/*----------------------------------------------------------------------------------------------------*/




void empiler(pile_t * pile, objet_t val)
{	

	  (pile->tab)[pile->NumeroSommet + 1] = val;             /*ajouter la valeur à la pile */

	  ++pile->NumeroSommet;	                                 /*augmenter le nombre d'element de la pile */

}







/*----------------------------------------------------------------------------------------------------*/
/* EstVide        Vérifie si la pile vide.                                                            */
/*                                                                                                    */
/* En entrée :    pile - Pointeur sur la structure de pile.                                           */
/*                vide - Pointeur sur la case mémoire contenant comme valeur vrai ou faux, pour dire  */
/*                       comme quoi la pile est respectivement vide ou pas.                           */
/*                                                                                                    */
/* En sortie :    vide - Pointeur sur la case mémoire contenant comme valeur vrai ou faux, pour dire  */
/*                       comme quoi la pile est respectivement vide ou pas.                           */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




void EstVide(pile_t * pile , enum BOOL * vide)
{
	*vide = faux;	

	if(pile->NumeroSommet == -1)
	  {

	    *vide = vrai ;

	  }

}







/*----------------------------------------------------------------------------------------------------*/
/* depiler        Retire la valeur au sommet et la supprime de la pile.                               */
/*                                                                                                    */
/* En entrée :   pile - Pointeur de la structure de pile.                                             */
/*                                                                                                    */
/* En sortie :   Retourne le sommet de la sommet.                                                     */
/*                                                                                                    */
/* Variable(s) locale(s) :    sommet - Contenant la valeur du sommet de la pile à etre supprimer de   */
/*                                     la pile.                                                       */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




objet_t depiler(pile_t * pile)
{
  objet_t sommet = (pile->tab)[pile->NumeroSommet];   /* sauvegarder le sommet*/

  --pile->NumeroSommet;                             /*deminuer le nombre d'element de la pile */

  return sommet;

}







/*----------------------------------------------------------------------------------------------------*/
/* SommetPile         Renvoie le sommet de la pile.                                                   */
/*                                                                                                    */
/* En entrée :    pile - Pointeur sur la structure de pile.                                           */
/*                                                                                                    */
/* En sortie :    La fonction retourne le sommet de la pile.                                          */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




objet_t SommetPile(pile_t * pile)
{

	return (pile->tab)[pile->NumeroSommet];

}








/*----------------------------------------------------------------------------------------------------*/
/* LibererPile         Libère la pile.                                                                */
/*                                                                                                    */
/* En entrée :     ppile - Pointeur de pointeur sur la structure de pile.                             */
/*                                                                                                    */
/* En sortie :     ppile - L'adresse du pointeur sur la structure de pile.                            */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




void LibererPile(pile_t ** ppile)
{

  free((*ppile)->tab);	/* désallouer le tab de donnees(implicitement la pile))*/

  free(*ppile);		/* désallouer la structure de pile */

  *ppile = NULL;

}







/*----------------------------------------------------------------------------------------------------*/
/* AfficherPile          Affiche le contenu de notre pile.                                            */
/*                                                                                                    */
/* En entrée :    pile - Pointeur sur la structure de pile.                                           */
/*                                                                                                    */
/* En sortie :    Rien en sortie.                                                                     */
/*                                                                                                    */
/* Variable(s) locale(s) : i - variable servant de variable de boucle.                                */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




void AfficherPile(pile_t * pile)
{

  int i;
  
  for(i = pile->NumeroSommet; i > -1; --i)
    {

      printf("%d\n", (pile->tab)[i]);

    }

}







/*----------------------------------------------------------------------------------------------------*/
/* TestFonctionPile          Procédure permettant d'utiliser et test le bon fonctionnement des        */
/*                           fonctions et procédures de pile.                                         */
/*                                                                                                    */
/* En entrée :    CodeLecture - Pointeur sur la case contenant une valeur entière comme quoi la       */
/*                              lecture c'est bien passé ou pas.                                      */
/*                                                                                                    */
/* En sortie :    CodeLecture - Pointeur sur la case contenant une valeur entière comme quoi la       */
/*                              lecture c'est bien passé ou pas.                                      */
/*                                                                                                    */
/* Variable(s) locale(s) :        choix - Variable permettant de gérer le menu fait avec le switch.   */
/*                            continuer - Variable permettant de faire choix de continuer l'exécution */
/*                                        ou pas.                                                     */
/*                               valeur - La valeur qui va etre dans la pile.                         */
/*                                 pile - Pointeur sur la structure de pile.                          */
/*                                 vide - Variable contenant vrai si la pile est vide et faux sinon.  */
/*                               pleine - Variable contenant vrai si la pile est pleine et faux sinon.*/
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




void TestFonctionPile(int * CodeLecture)
{

  int choix, continuer;

  objet_t valeur;

  pile_t * pile = InitialisationPile(TAILLE_MAX);
  
  enum BOOL vide, pleine;
 
  
  if(pile != NULL)                                         /*si l'allocation de la pile c'est bien passé*/
    {
      
      do
	{
	  
	  printf("Veuillez faire un choix!\n");
	  
	  printf("1. Tester si la pile est vide.\n");
	  
	  printf("2. Tester si la pile est pleine.\n");
	  
	  printf("3. Empiler.\n");
	  
	  printf("4. Depiler.\n");
	  
	  printf("5. Sommet de la pile.\n");
	  
	  *CodeLecture = scanf("%d", &choix);

	  if(*CodeLecture)                                                /*si lecture c'est bien passé*/
	    {
	  
	      switch(choix)
		{
		  
		case 1:
		  
		  EstVide(pile,&vide);                                        /*cherche si la pile est vide*/
		  
		  if(vide)                                                    /*si elle vide*/
		    {
		      
		      printf(" La pile est vide. ");
		      
		    }
		  else                                                       /*si elle n'est pas vide*/
		    {
		      
		      printf("La pile n'est pas vide.\n");
		      
		    }
		  
		  break;
		  
		case 2:
		  
		  EstPleine(pile,&pleine);                                   /*vérifie si la pile est pleine*/
		  
		  if(pleine)                                                 /*si elle est pleine*/
		    {
		      
		      printf(" La pile est pleine. ");
		      
		    }
		  else                                                      /*si elle n'est pas pleine*/
		    {
		      
		      printf("La pile n'est pas pleine.\n");
		      
		    }
		  
		  break;
		  
		case 3:
		  
		  EstPleine(pile, &pleine);                                 /*vérifie si la pile est pleine*/
		  
		  if(!pleine)                                               /*si elle n'est pas pleine*/
		    {
		      printf("Le cotenu de la pile avant d'empiler.\n");
		      
		      AfficherPile(pile);
		      
		      printf("Veuillez entrer le chiffre à empiler\n");
		      
		      *CodeLecture = scanf("%d", &valeur);
		      
		      if(*CodeLecture)                                          /*si la lecture c'est bien passé*/
			{
			  
			  empiler(pile, valeur);                                /*empiler la valeur*/
			  
			  printf("Le cotenu de la pile après avoir empiler.\n");
			  
			  AfficherPile(pile);
			}
		      
		    }
		  else
		    {
		      
		      printf("La pile est pleine.\n");
		      
		    }
		  
		  break;
		  
		case 4:
		  
		  EstVide(pile, &vide);                                     /*vérifie si la pile est vide*/
		  
		  if(!vide)                                                 /*si elle n'est pas vide*/
		    {
		      
		      printf("Le cotenu de la pile avant de dépiler.\n\n");
		      
		      AfficherPile(pile);
		      
		      printf("La valeur dépiler est:\n %d\n\n", depiler(pile));
		      
		      printf("Le cotenu de la pile après avoir dépiler.\n\n");
		      
		      AfficherPile(pile);
		      
		    }
		  else
		    {
		      
		      printf("La pile est vide.\n");
		      
		    }
		  
		  break;
		  
		case 5:
		  
		  EstVide(pile, &vide);                                              /*vérifie si la pile est vide*/
		  
		  if(!vide)                                                          /*si la pile n'est pas vide*/
		    {
		      printf("Le cotenu de la pile est:\n\n");
		      
		      AfficherPile(pile);
		      
		      printf("Le sommet de la pile est:\n %d\n", SommetPile(pile));
		      
		    }
		  else
		    {
		      
		      printf("La pile est vide.\n");
		      
		    }
		  
		  break;
		  
		default:
		  
		  printf("Veuillez entrer le bon numéro!\n");
		}
	    }
	  
	  printf("\nVoulez-vous continuer? 1 = OUI  0 = NON\n");
	  
	  *CodeLecture = scanf("%d", &continuer);
	  
	}while((continuer && *CodeLecture) && (pile->NumeroSommet < TAILLE_MAX));
      
      LibererPile(&pile);
      
    }
  
}
