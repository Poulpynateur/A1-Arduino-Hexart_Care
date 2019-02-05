#include <stdlib.h>
#include <stdio.h>

#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

#define EXIT_FAILURE 1

//Element de notre liste
typedef struct element Element;
struct element
{
	char date[10];
    //Un element pour le temps
	int time;
	//Un element pour le pouls
	int bpm;

	//Les adresses des elements suivants et précedents.
    Element *previous;
	Element *next;
};

//Premeier element de notre liste
typedef struct list List;
struct list
{
	Element *first;
};

List *initialization();
void add(List *list);
List *stackfile();

#endif
