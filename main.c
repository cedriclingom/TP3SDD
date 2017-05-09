#include "./dico.h"



int main(int argc, char ** argv)
{

  enum bool CodeLecture;

  lettre_t * pdico = NULL;

  if(argc == 2)
    {

      LectureFichier(argv[1], &pdico, &CodeLecture);

      AffichageDico(pdico);

      LibererDico(&pdico);
		     
    }
  else
    {

      printf("Veuiilez entrer le bon nombre d'arguments!\n");

    }


  return 0;

}
