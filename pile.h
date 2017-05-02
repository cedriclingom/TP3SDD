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




#define TAILLE_MAX 10               /*Taille utiliser pour tester les fonctions de pile*/














enum BOOL{faux, vrai};




typedef lettre_t * objet_t; 

typedef struct pile
{

    int taille;

    int NumeroSommet;

    objet_t * tab;

} pile_t;








pile_t * InitialisationPile(int);

void EstPleine(pile_t *, enum BOOL *);

void empiler(pile_t *, objet_t);

void EstVide(pile_t *, enum BOOL *);

objet_t depiler(pile_t *);

objet_t SommetPile(pile_t *);

void LibererPile(pile_t **);

void AfficherPile(pile_t *);

void TestFonctionPile(int *);





#endif
