/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/*                                             lettre.c                                               */
/*                                                                                                    */
/* Role : Définition des procédures et fonctions permettant la gestion des lettres.                   */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




#include "./lettre.h"






/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* AllocationLettre            Alloue le bloc devant contenir la lettre.                              */
/*                                                                                                    */
/* En entrée             :        Rien en entrée.                                                     */
/*                                                                                                    */
/* En sortie             : pcar - Pointeur du bloc alloué devant contenir la lettre.                  */
/*                                                                                                    */
/* Variable(s) locale(s) : pcar - Pointeur du bloc alloué devant contenir la lettre.                  */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


lettre_t * AllocationLettre()
{

  lettre_t * pcar = (lettre_t *)malloc(TAILLELETTRE * sizeof(lettre_t));

  if (pcar != NULL)                                                       /*si l'allocation c'est bien passé*/
    {

      pcar->lv = NULL;

      pcar->lh = NULL;

    }
  
  return pcar;

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* EstMiniscule            Test si le lettre en minuscule.                                            */
/*                                                                                                    */
/* En entrée             : pcar      - Pointeur sur le bloc contenant la lettre à tester.             */
/*                                                                                                    */
/* En sortie             : minuscule - Contentant vrai si la lettre est en minuscule et faux si       */
/*                                     la lettre est en majuscule.                                    */
/*                                                                                                    */
/* Variable(s) locale(s) : minuscule - Contentant vrai si la lettre est en minuscule et faux si       */
/*                                     la lettre est en majuscule.                                    */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


enum bool EstMiniscule(lettre_t * pcar)
{

  enum bool minuscule = faux;                             /*on suppose qu'il n'est pas minuscule*/

  if((pcar->valeur >= 'a') && (pcar->valeur <= 'z'))       /*s'il est minuscule*/
    {

      minuscule = vrai;

    }

  return minuscule;

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* EstMajuscule            Test si la lettre en majuscule.                                            */
/*                                                                                                    */
/* En entrée             : pcar      - Pointeur sur le bloc contenant la lettre à tester.             */
/*                                                                                                    */
/* En sortie             : majuscule - Contentant vrai si la lettre est en majuscule et faux si       */
/*                                     la lettre est en minuscule.                                    */
/*                                                                                                    */
/* Variable(s) locale(s) : majuscule - Contentant vrai si la lettre est en majuscule et faux si       */
/*                                     la lettre est en minuscule.                                    */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


enum bool EstMajuscule(lettre_t * pcar)
{

  enum bool majuscule = faux;                             /*on suppose qu'il n'est pas en majuscule*/

  if((pcar->valeur >= 'A') && (pcar->valeur <= 'Z'))       /*s'il est minuscule*/
    {

      majuscule = vrai;

    }

  return majuscule;

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* EnMajuscule            Transforme une lettre en majuscule.                                         */
/*                                                                                                    */
/* En entrée             : pcar - Pointeur sur le bloc contenant la lettre.                           */
/*                                                                                                    */
/* En sortie             : pcar - Pointeur sur le bloc contenant la lettre.                           */
/*                                                                                                    */
/* Variable(s) locale(s) :        Rien en variable locale.                                            */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


void EnMajuscule(lettre_t * pcar)
{

  pcar->valeur = pcar->valeur - ('a' - 'A');

}



/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* EnMinuscule            Transforme une lettre en minuscule.                                         */
/*                                                                                                    */
/* En entrée             : pcar - Pointeur sur le bloc contenant la lettre.                           */
/*                                                                                                    */
/* En sortie             : pcar - Pointeur sur le bloc contenant la lettre.                           */
/*                                                                                                    */
/* Variable(s) locale(s) :        Rien en variable locale.                                            */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


void EnMinuscule(lettre_t * pcar)
{

  pcar->valeur = pcar->valeur + ('a' - 'A');

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* CompareLettre            Compare deux lettre sans tenir compte des majuscules.                     */
/*                                                                                                    */
/* En entrée             : c           - Variable contenant la première lettre.                       */
/*                         pcar        - Ponteur sur un bloc contenant la deuxième lettre.            */
/*                         comparaison - Pointeur sur une case mémoire contenant une valeur positive  */
/*                                       si la première lettre > la deuxième, une valeur négative si  */
/*                                       la première lettre <  la deuxième et zéro s'ils sont égaux.  */
/*                                                                                                    */
/* En sortie             : comparaison - Pointeur sur une case mémoire contenant une valeur positive  */
/*                                       si la première lettre > la deuxième, une valeur négative si  */
/*                                       la première lettre <  la deuxième et zéro s'ils sont égaux.  */
/*                                                                                                    */
/* Variable(s) locale(s) :               Rien comme variable locale.                                  */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/



void CompareLettre(char c, lettre_t * pcar, int * comparaison)
{

  *comparaison = -1;

  if(pcar)
    {

      if(EstMajuscule(pcar))
	{
	  
	  *comparaison = c - (pcar->valeur + ('a' - 'A'));
	  
	}
      else
	{
	  
	  *comparaison = c - pcar->valeur;
	  
	}
      
    }

}


/*------------------------------------------------------------------------------------------------------*/
/* RechercherPrec          Recherche une lettre dans la liste chainée des lettres.                      */
/*                                                                                                      */
/* En entrée             : PpteteListe - Pointeur de pointeur de tête de la liste chainée des lettres.  */
/*                         lettre      - Pointeur sur la lettre à rechercher.                           */
/*                         ptrouver    - Pointeur sur une case mémoire contenant 0 si on a pas trouvé   */
/*                                       ou 1 si on a trouvé la lettre.                                 */
/*                                                                                                      */
/* En sortie             : prec        - Retourne l'adresse du pointeur de tete de liste chainée des    */
/*                                       lettres ou l'adresse de la case pointeur de l'élément précédent*/
/*                                       dans la liste chainée des lettres.                             */
/*                         ptrouver    - Pointeur sur une case mémoire contenant 0 si on a pas trouvé   */
/*                                       l'élément ou 1 si on a trouvé dans la liste chainée des lettres*/
/*                                                                                                      */
/* Variable(s) locale(s) : pcour       - Pointeur sur la lettre courante.                               */
/*                         prec        - Pointeur de pointeur de tete de liste chainée des lettres ou   */
/*                                       pointeur sur la case pointeur de l'élément précédent de la     */
/*                                       liste chainée des lettres.                                     */
/*                         comparaison - Variable le résultat de la comparaison de deux lettres qui sera*/
/*                                       postif si la première lettre > la deuxième lettre, négatif si  */
/*                                       la première lettre < la deuxième lettre et zéro s'ils sont     */
/*                                       égaux.                                                         */
/*                                                                                                      */
/*------------------------------------------------------------------------------------------------------*/


lettre_t **  RechercherPrec (lettre_t ** PpteteListe, char lettre, enum bool * ptrouver)
{

  int comparaison;

  lettre_t * pcour = *PpteteListe, ** prec = PpteteListe;           /*Initialisation à la première lettre et au pointeur de tete*/

  *ptrouver = faux;

  CompareLettre(lettre, pcour, &comparaison);

  while((pcour != NULL) && (comparaison > 0)) /*Tantque je suis dans la liste et que ma lettre est plus grande*/
    {
      
      prec = &(pcour->lh);                                    /*On récupère l'adresse de la case pointeur de l'élément courant*/
      
      pcour = *prec;                                                 /*Passe au suivant*/

      CompareLettre(lettre, pcour, &comparaison);
      
    }

  if ((pcour != NULL) && !(comparaison))         /*Si on trouve la lettre*/
    {

      *ptrouver = vrai;

    }

  return prec;

}


/*--------------------------------------------------------------------------------------------------------*/
/* InsertionLettre         Insère une nouvelle lettre dans la liste chainée des lettres.                  */ 
/*										     			  */ 
/* En entrée             : ppcar - Pointeur de pointeur de tete de liste chainée des lettres ou pointeur  */
/*                                 sur la case pointeur de l'élément précédent.                           */ 
/*	                   pcar  - Pointeur sur le bloc contenant la lettre à insérer.                    */
/*                                                                                                        */
/* En sortie             : ppcar - Pointeur de pointeur de tete de liste chainée des lettres ou pointeur  */
/*                                 sur la case pointeur de l'élément précédent.                           */
/*                                                                                                        */
/* Variable(s) locale(s) : Rien en variable locale.                                                       */
/*                                                                                                        */
/*--------------------------------------------------------------------------------------------------------*/



void InsertionLettre (lettre_t ** ppcar, lettre_t * pcar)
{

  pcar->lh = *ppcar;

  *ppcar = pcar;

  pcar = NULL;

}


/*-------------------------------------------------------------------------------------------------------*/
/* SuppressionAction          Supprime une lettre de liste chainée courante des lettres.                 */ 
/*										     			 */ 
/* En entrée             : ppcar - Pointeur de pointeur de tete de liste chainée courante des lettres    */
/*                                 ou pointeur sur la case pointeur de l'élément précédent de la liste   */
/*                                 chainée courante des lettres.                                         */                  
/*                                                                                                       */
/* En sortie             : ppcar - Pointeur de pointeur de tete de liste chainée courante des lettres    */
/*                                 ou pointeur sur la case pointeur de l'élément précédent de la liste   */
/*                                   chainée courante des lettres.                                       */ 
/* Variable(s) locale(s) : pcar - Pointeur sur lettre à supprimer.                                       */
/*-------------------------------------------------------------------------------------------------------*/


void SuppressionLettre(lettre_t ** ppcar)
{

  lettre_t * pcar = *ppcar;     /*recupère l'adresse de lettre à supprimer*/

  *ppcar = pcar->lh;            /*pointe sur la lettre après la lettre à supprimer*/

  free(pcar);                   /*supprime la lettre*/

  pcar = NULL;

}
