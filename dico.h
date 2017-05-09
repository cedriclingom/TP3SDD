/*----------------------------------------------------------------------------------------------------*/
/*                                                dico.h                                              */
/*                                                                                                    */
/* Role : Déclaration des directives de compilation, des constantes symboliques, des types            */
/*        personnels et des prototypes.                                                               */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/







#ifndef GESTION_DICTIONNAIRE_ABORESCENTE_DICO_H
#define GESTION_DICTIONNAIRE_ARBORESCENTE_DICO_H







#include "./pile.h"
#include "./lettre.h"






#define TAILLEMOT 50







void LectureMot(FILE *, char *, enum bool *);

lettre_t ** RechercheDivergence(char *, int *, lettre_t **);

void InsertionMot(char *, int *, lettre_t **, enum bool *);

void CreerDico(lettre_t **, FILE *, enum bool *);

void LectureFichier(char *, lettre_t **, enum bool *);

void AffichageDicoAvecMotif(lettre_t *, char *);

void AffichageDico(lettre_t *);

void RechercheMotif(lettre_t *, char *);

void RechercheDico(lettre_t *);

void LibererDico(lettre_t **);




#endif
