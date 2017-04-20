/*----------------------------------------------------------------------------------------------------*/
/*                                              caractere.h                                           */
/*                                                                                                    */
/* Role : Déclaration des directives de compilation, constantes symboliques, types et prototypes.     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




#ifndef GESTION_DICTIONNAIRE_ARBORESCENT_CARACTERE_H
#define GESTION_DICTIONNAIRE_ARBORESCENT_CARACTERE_H





#include <stdio.h>
#include <stdlib.h>








#define TAILLECAR 3





typedef struct caractere
{
  
  char valeur;
  
  struct caractere * lv;
  
  struct caractere * lh;

}caractere_t;




enum bool{faux, vrai};





caractere_t * AllocationCaractere();

enum bool EstMiniscule(caractere_t *);

enum bool EstMajuscule(caractere_t *);







#endif
