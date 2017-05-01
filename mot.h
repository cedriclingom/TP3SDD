/*----------------------------------------------------------------------------------------------------*/
/*                                               mot.h                                                */
/*                                                                                                    */
/* Role : Déclaration des directives de compilation, constantes symboliques, types et prototypes.     */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/





#ifndef GESTION_DICTIONNAIRE_AARBORESCENTE_MOT_H
#define GESTION_DICTIONNAIRE_AARBORESCENTE_MOT_H







#include "./lettre.h"






#define TAILLEMOT 50





void LectureMot(FILE *, char *, enum bool *);

lettre_t ** RechercheDivergence(char *, int *, lettre_t **);

void InsertionMot(char *, int *, lettre_t **, enum bool *);


#endif
