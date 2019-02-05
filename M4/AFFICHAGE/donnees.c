#include "donnees.h"

//Initialiser notre liste
List *initialization()
{
    List *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)

    {
        printf("Erreur : initialisation.\n");
        exit(EXIT_FAILURE);
    }

    element->time = 0;
    element->bpm = 0;

    element->previous = NULL;
    element->next = NULL;

    liste->first = element;

return liste;
}

//Ajouter un element a notre liste (qui est une file)
void add(List *list)
{
    Element *new = malloc(sizeof(*new));

    if (list == NULL || new == NULL)
    {
        printf("Erreur : ajout d'un element.\n");
        exit(EXIT_FAILURE);
    }

    new->time = 0;
    new->bpm = 0;

    new->previous = NULL;
    new->next = NULL;

    if (list->first != NULL) //La file n'est pas vide
    {
        //On se positionne à la fin de la file
        Element *elementActual = list->first;

        while (elementActual->next != NULL)
        {
            elementActual = elementActual->next;
        }
        new->previous = elementActual;
        elementActual->next = new;
    }

    else //La file est vide, notre élément est le premier
    {
        list->first = new;
    }
}

List *stackfile()
{
    FILE* file = NULL;

    List *test = initialization();
    Element *actual = NULL;
    int H = 0;
    int M = 0;
    int S = 0;

    //Recuperation fichier .csv
    file = fopen("..\\..\\M3\\ConvertisseurSerialCSV\\Battements.csv", "r");

    if (file != NULL)
    {
    	actual = test->first;

        //Tant qu'on est pas en fin de fichier
        while (feof(file) == 0)
        {
            //Lecture du fichier et stockage dans une liste
            //Ces elements sont enregistrer en milliscondes et en battement par 15s
        	fscanf(file, "%6s;%d:%d:%d;%d;\n",&(actual->date),&H,&M,&S, &(actual->bpm));
            actual->time = H*60*60+ M*60 + S;
            add(test);
            actual = actual->next;
        }
    	fclose(file); // On ferme le fichier qui a été ouvert
    }
    else
    {
    	printf("Fail : open .csv");
    	exit(EXIT_FAILURE);
    }

//Renvoie l'adresse de la liste
return test;
}


