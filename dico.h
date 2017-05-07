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
#include "./mot.h"





void CreerDico(lettre_t **, FILE *, enum bool *);

void LectureFichier(char *, lettre_t **, enum bool *);

void AffichageDicoParOrdreAlpha(lettre_t *);

void LibererDico(lettre_t **);




#endif
