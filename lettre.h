/*----------------------------------------------------------------------------------------------------*/
/*                                              lettre.h                                              */
/*                                                                                                    */
/* Role : Déclaration des directives de compilation, constantes symboliques, types et prototypes.     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




#ifndef GESTION_DICTIONNAIRE_ARBORESCENT_LETTRE_H
#define GESTION_DICTIONNAIRE_ARBORESCENT_LETTRE_H





#include <stdio.h>
#include <stdlib.h>








#define TAILLELETTRE 3





typedef struct lettre
{
  
  char valeur;
  
  struct lettre * lv;
  
  struct lettre * lh;

}lettre_t;




enum bool{faux, vrai};





lettre_t * AllocationLettre();

enum bool EstMiniscule(lettre_t *);

enum bool EstMajuscule(lettre_t *);

void EnMajuscule(lettre_t *);

void EnMinuscule(lettre_t *);

lettre_t **  RechercherPrec (lettre_t **, char, enum bool *);

void InsertionLettre (lettre_t **, lettre_t *);



#endif
