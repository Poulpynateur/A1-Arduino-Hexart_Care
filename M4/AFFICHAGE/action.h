#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

void color(int t,int f) ;
int affiche(List *liste);
int nbr_ligne(List *liste);
int moyenne(List *liste);
int recherche(List *liste);
int tri_Dtemps(List *liste);
int tri_Cpouls(List *liste);
int tri_Dpouls(List *liste);
int number_max(List *liste);
int number_min(List *liste);
void refresh(List *liste);
void aberrante(List *liste);
void logo_exia();

#endif
