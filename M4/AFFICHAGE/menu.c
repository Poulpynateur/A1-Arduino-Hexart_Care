#include "menu.h"

int menu(List *liste)
{
	int choix = 0;
	printf("\n*******************************************************\
            \n| 1 - Afficher les donnees.                           |\
			\n| 2 - Trier et afficher des donnees.                  |\
			\n| 3 - Nombre de lignes en memoires.                   |\
			\n| 4 - Moyenne des valeurs sur un intervalle.          |\
			\n| 5 - Recherche en fonction d'un intervalle de temps. |\
            \n| 6 - Pouls maximum et pouls minimum.                 |\
            \n| 7 - Suppression valeurs aberantes.                  |\
            \n| 8 - Recharger le .csv                               |\
            \n| 9 - Logo Exia.                                      |\
            \n| 10 - Faire un cafe.                                 |\
            \n|                                                     |\
			\n| 0 - Quitter.                                        |\
            \n*******************************************************\n");
	printf("\nEntrez un choix : ");
	scanf("%d", &choix);
	printf("\n");

	switch (choix)
	{
	    //Afficher les donnees.
		case 1:
			affichage_full(liste);
			return menu(liste);

        //Trier et afficher des donnees.
        case 2:
        	printf("1 - Tri croissant : temps.\n2 - Tri decroissant : temps.\n3 - Tri croissant : pouls.\n4 - Tri decroissant : pouls.\n");
        	printf("\nEntrez un sous-choix : ");
        	scanf("%d", &choix);
        	printf("\n");

        	switch (choix)
        	{
        		case 1:
        			affichage_full(liste);
        			break;
        		case 2:
                    tri_Dtemps(liste);
        			break;
        		case 3:
                    tri_Cpouls(liste);
                    affichage_full(liste);
        			break;
        		case 4:
                    tri_Dpouls(liste);
                    affichage_full(liste);
        			break;
        		default:
        			printf("Choix invalide.\n");
					return menu(liste);
        	}
            return menu(liste);

        //Nombre de lignes en memoires.
		case 3:
			printf("Nombre de lignes : %d\n",nbr_ligne(liste));
			return menu(liste);

        //Moyenne des valeurs sur un intervalle.
        case 4:
            printf("Moyenne des pouls : %d\n", moyenne(liste));
            return menu(liste);

        //Recherche en fonction d'un interval de temps.
        case 5:
            recherche(liste);
            return menu(liste);

        //Pouls maximum et pouls minimum.
        case 6:
            printf("Pouls max : %d\n", number_max(liste));
            printf("Pouls min : %d\n", number_min(liste));
            return menu(liste);

        //Aberante
        case 7:
            aberrante(liste);
            return menu(liste);
        //Refresh
        case 8:
        	refresh(liste);
        	return menu(liste);
        //Exit.
        case 9:
            logo_exia();
            return menu(liste);
        //Cafe
        case 10:
            system("start Bonus.exe");
            return menu(liste);
		case 0:
			exit(0);

        //Gestion des entrees inconnues
		default:
			printf("Choix invalide.\n");
			return menu(liste);
	}

return 0;
}
