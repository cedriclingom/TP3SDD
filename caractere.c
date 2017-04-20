/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/*                                          caractere.c                                               */
/*                                                                                                    */
/* Role : Définition des procédures et fonctions permettant la gestion des caractères.                */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




#include "./caractere.h"






/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* AllocationCaractere            Alloue le bloc devant contenir le caractere.                        */
/*                                                                                                    */
/* En entrée             :        Rien en entrée.                                                     */
/*                                                                                                    */
/* En sortie             : pcar - Pointeur du bloc alloué devant contenir le caractère.               */
/*                                                                                                    */
/* Variable(s) locale(s) : pcar - Pointeur du bloc alloué devant contenir le caractère.               */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


caractere_t * AllocationCaractere()
{

  caractere_t * pcar = (caractere_t *)malloc(TAILLECAR * sizeof(caractere_t));

  if (pcar)                                                       /*si l'allocation c'est bien passé*/
    {

      pcar->lv = NULL;

      pcar->lh = NULL;

    }
  
  return pcar;

}


/*----------------------------------------------------------------------------------------------------*/
/*                                                                                                    */
/* EstMiniscule            Test si le caractère en minuscule.                                         */
/*                                                                                                    */
/* En entrée             : pcar      - Pointeur sur le bloc contenant le caractère à tester.          */
/*                                                                                                    */
/* En sortie             : minuscule - Contentant vrai si le caractère est en minuscule et faux si    */
/*                                     le caractère est en majuscule.                                 */
/*                                                                                                    */
/* Variable(s) locale(s) : minuscule - Contentant vrai si le caractère est en minuscule et faux si    */
/*                                     le caractère est en majuscule.                                 */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


enum bool EstMiniscule(caractere_t * pcar)
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
/* EstMajuscule            Test si le caractère en majuscule.                                         */
/*                                                                                                    */
/* En entrée             : pcar      - Pointeur sur le bloc contenant le caractère à tester.          */
/*                                                                                                    */
/* En sortie             : majuscule - Contentant vrai si le caractère est en majuscule et faux si    */
/*                                     le caractère est en minuscule.                                 */
/*                                                                                                    */
/* Variable(s) locale(s) : majuscule - Contentant vrai si le caractère est en majuscule et faux si    */
/*                                     le caractère est en minuscule.                                 */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/


enum bool EstMajuscule(caractere_t * pcar)
{

  enum bool majuscule = faux;                             /*on suppose qu'il n'est pas en majuscule*/

  if((pcar->valeur >= 'A') && (pcar->valeur <= 'Z'))       /*s'il est minuscule*/
    {

      majuscule = vrai;

    }

  return majuscule;

}




/*EnMajuscule*/
/*EnMinuscule*/
