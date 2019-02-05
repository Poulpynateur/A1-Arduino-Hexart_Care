#include "param.h"
#include "coeur.c"

int pinLed[10]= {3,2,4,5,6,7,8,9,10,11};
int i=0;
int n=0;

void (*fonction)(int i ,int n ,int pinLed[]);

void setup() 
{
//initialisation des variables
  for(i = 0; i < 10; i++)
  {
    pinMode(pinLed[i], OUTPUT); //on utilise les valeurs du tableau
    digitalWrite(pinLed[i], LOW); // l'une après l'autre
  }
  switch (CHOIX)
  {
    case 1:
      fonction = coeur_simple;
      break;
    case 2:
      fonction = coeur_1sur_n;
      break;
    case 3:
      fonction = coeur_un;
      break;
    case 4:
      fonction = coeur_chenille;
      break;
    case 5:
      fonction = coeur_all;
      break;
    case 6:
      fonction = coeur_aller_retour;
      break;
    case 7:
      fonction = coeur_sapin;
      break;
    default :
      fonction = coeur_all;
      break;
  }
}

void loop() 
{
  (*fonction)(i,n,&pinLed[0]);
}

