#include "generationCode.h"

void color(int t,int f) //Couleur dans la console
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}

//Creation du fichier param.h
void generation(int choix, int complement_choix)
{
	FILE* fichier = NULL;
	fichier = fopen("..\\coeur\\param.h","w");

	//Si le fichier est crée
	if (fichier != NULL)
	{
		fprintf(fichier, "#define CHOIX %d\n",choix);
		fprintf(fichier, "#define COMPLEMENT %d\n",complement_choix);
		fprintf(fichier, "#define BPM %d\n",(((60*1000)/get_bpm()))/2);
		fclose(fichier);

		//On affiche un message de succes (en vert !)
		color(10,0);
		printf("Fichier param.h creer avec succes !\n");
		color(15,0);
	}
}

//On recupere le BPM moyen du fichier
int get_bpm()
{
	int bpm = 0, tmp = 0, i = 0;

	FILE* fichier = NULL;
	fichier = fopen("..\\..\\M3\\ConvertisseurSerialCSV\\Battements.csv","r");

	if (fichier != NULL)
	{
		while (feof(fichier) == 0)
        {
        	//On recupere le BPM moyen du fichier

        	fscanf(fichier, "%*6s;%*d:%*d:%*d;%d;\n", &tmp);
            bpm += tmp;

            i += 1;
        }
        bpm = bpm/i;
		fclose(fichier);
	}
	else
	{
		printf("Fail : open .csv");
    	exit(EXIT_FAILURE);
	}

//On retourn se BPM
return bpm;
}
