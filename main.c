#include "./dico.h"



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
