/*----------------------------------------------------------------------------------------------------*/
/*                                              pile.h                                                */
/*                                                                                                    */
/* Role : Déclaration des directives de compilation, constantes symboliques, types et prototypes.     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




#ifndef DERECURSIVITE_PILE_H
#define DERECURSIVITE_PILE_H



#include <stdio.h>
#include <stdlib.h>
#include "./lettre.h"




#define TAILLE_MAX 40               /*Taille utiliser pour tester les fonctions de pile*/













typedef lettre_t * objet_t; 

typedef struct pile
{

    int taille;

    int NumeroSommet;

    objet_t * tab;

} pile_t;








pile_t * InitialisationPile(int);

void empiler(pile_t *, objet_t);

void EstVide(pile_t *, enum bool *);

objet_t depiler(pile_t *);

objet_t SommetPile(pile_t *);

void AffichageContenuPile(pile_t *);

void LibererPile(pile_t **);





#endif
