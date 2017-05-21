/*-----------------------------------------------------------------------------------------------*/
/*                                                                                               */
/*                                           main.c                                              */
/* Role :  Contient notre fonction principale main qui fait à d'autres fonctions et procédurés   */
/*         tels que: LectureFichier, AffichageDico, RechercheDico, LibererDico qui permettent des*/
/*         sur le dictionnaire.                                                                  */
/*                                                                                               */
/*-----------------------------------------------------------------------------------------------*/


#include "./dico.h"





/*-----------------------------------------------------------------------------------------------*/
/*                                                                                               */
/* main          Fonction principale faisant à des fonctions et procédures qui permettent        */
/*               des traitement sur le dictionnire.                                              */
/*                                                                                               */
/* En entrée             : argc        - Compte de le nombre d'arguments passés en ligne de      */
/*                                       commande.                                               */
/*                         argv        - Tableau de pointeur sur des chaines caractères qui sont */
/*                                       rien d'autres que les arguments passés en ligne de      */
/*                                       commande.                                               */
/*                                                                                               */
/* En sortie             :               Rien en sortie.                                         */
/*                                                                                               */
/* Variable(s) locale(s) : CodeLecture - Variable contenant vrai si la lecture à partir du       */
/*                                       fichier c'est passé et faux sinon.                      */
/*                         pdico       - Pointeur de tete de la première liste chainée de lettres*/
/*                                       (liste chainée des racines).                            */
/*                                                                                               */
/*-----------------------------------------------------------------------------------------------*/





int main(int argc, char ** argv)
{

  enum bool CodeLecture;

  lettre_t * pdico = NULL;

  if(argc == 2)
    {

      LectureFichier(argv[1], &pdico, &CodeLecture);

      if(CodeLecture)
	{

	  AffichageDico(pdico);                 /*Affiche le dictionnaire sans motif*/
	  
	  RechercheDico(pdico);                 /*Reherche un motif et affiche les mots d'un dictionnaire qui commence par ce motif*/
	  
	  LibererDico(&pdico);

	}
      else
	{
	  
	  printf("Erreur de lecture dans le fichier!");

	}
		     
    }
  else
    {

      printf("Veuiilez entrer le bon nombre d'arguments!\n");

    }


  return 0;

}
