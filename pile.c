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

  (pile->tab)[(pile->NumeroSommet) + 1] = val;           /*ajouter la valeur à la pile */

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




void EstVide(pile_t * pile , enum bool * vide)
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

  --pile->NumeroSommet;                               /*deminuer le nombre d'element de la pile */

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
/* AfficherContenuPile          Affiche le contenu des pointeurs dans de notre pile.                         */
/*                                                                                                    */
/* En entrée :    pile - Pointeur sur la structure de pile.                                           */
/*                                                                                                    */
/* En sortie :    Rien en sortie.                                                                     */
/*                                                                                                    */
/* Variable(s) locale(s) : i - variable servant de variable de boucle.                                */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/

void AffichageContenuPile(pile_t * pile)
{
	int i ;

	for(i = 0; i <= pile->NumeroSommet; ++i)
	{

		if(EstMajuscule((pile->tab)[i]))
		  {
		    
		    printf("%c",(((pile->tab)[i])->valeur) + ('a' - 'A'));

		  }
		else
		  {

		    printf("%c",((pile->tab)[i])->valeur);

		  }

	}

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

