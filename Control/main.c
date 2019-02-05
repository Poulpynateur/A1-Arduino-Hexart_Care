#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int choix = 0;

	printf("*********************\n\
| 1 - Module 1      |\n\
| 2 - Module 2      |\n\
| 3 - Module 3      |\n\
| 4 - Module 4      |\n\
|                   |\n\
| 0 - Exit          |\n\
*********************\n");

    printf("Entrer un choix : ");scanf("%d",&choix);
	switch (choix)
	{
		case 1:
			system("start ..\\M1\\main\\main.ino");
			return main();
		case 2:
			system("start ..\\M2\\Generation\\Projet-1-COEUR.cbp");
			return main();
		case 3:
			system("start ..\\M3\\ConvertisseurSerialCSV\\ConvertisseurSerialCSV.pde");
			return main();
		case 4:
			system("start ..\\M4\\AFFICHAGE\\Projet_1.cbp");
			return main();
		default:
			exit(1);
	}
return 0;
}
