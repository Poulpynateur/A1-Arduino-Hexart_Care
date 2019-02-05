#include "menu.h"
#include "generationCode.h"

void menu()
{
    color(15,0);
    int choix = 0, complement = 0;
    printf("\n*******************************************************\
        	\n| 1 - Allumage standard                               |\
			\n| 2 - Allumage 1 LED sur 2,3,4 ou 5                   |\
			\n| 3 - Allumage d'une seul LED                         |\
			\n| 4 - Allumage chenille                               |\
            \n| 5 - Allumage toutes                                 |\
            \n| 6 - Allumage aller-retour                           |\
            \n| 7 - Allumage sapin                                  |\
	        \n|                                                     |\
			\n| 0 - Quitter.                                        |\
	        \n*******************************************************\n");

    printf("Entrez votre choix : ");scanf("%d", &choix);

    switch (choix)
    {
    	case 1:
    		generation(1,0);
    		exit(0);
    	case 2:
    	    printf("Nombre de sauts (2,3,4 ou 5) : ");scanf("%d", &complement);
    	    generation(2,complement);
    		exit(0);
    	case 3:
    	    printf("Quelle LED ? (de 0 a 9) : ");scanf("%d", &complement);
    	    generation(3,complement);
    		exit(0);
    	case 4:
    	    generation(4,0);
    		exit(0);
    	case 5:
    	    generation(5,0);
    		exit(0);
        case 6:
            generation(6,0);
            exit(0);
        case 7:
            generation(7,0);
            exit(0);

    	case 0:
    	    exit(0);
    	default:
    		printf("Choix invalide.\n");
    		return menu();
    }
}
