#include "coeur.h"

void coeur_1sur_n(int i,int n,int pinLed[])
{
  for (n = 0; n < 10; n++)
  {
    for (i = 0; i < 10; i++)
    {
        if ((i+n)%COMPLEMENT == 0)
        {
            digitalWrite(pinLed[i], HIGH);
            delay(BPM);
        }
        else
        {
            digitalWrite(pinLed[i], LOW);
            delay(BPM);
        }
    }
  }
}

void coeur_un(int i,int n,int pinLed[])
{
  digitalWrite(pinLed[COMPLEMENT], HIGH);
  delay(BPM);
  digitalWrite(pinLed[COMPLEMENT], LOW);
  delay(BPM);
}

void coeur_simple(int i,int n,int pinLed[])
{
  for (i=0;i<10;i++)
  {
      digitalWrite(pinLed[i],HIGH);
      delay(BPM);
  }

  for (i=10;i>=0;i--)
  {
        digitalWrite(pinLed[i],LOW);
        delay(BPM);
  }
  
}

void coeur_chenille(int i,int n,int pinLed[])
{
  for( i=0;i<10;i++)
  {
    digitalWrite(pinLed[i], HIGH);
    delay(BPM);
    digitalWrite(pinLed[i], LOW);
    delay(BPM);
  }
}

void coeur_all(int i,int n,int pinLed[])
{
  for( i=0;i<10;i++)
  {
    digitalWrite(pinLed[i], HIGH);
  }
  delay(BPM);
  
  for( i=0;i<10;i++)
  {
    digitalWrite(pinLed[i], LOW);
  }
  delay(BPM);
  
}

void coeur_aller_retour(int i,int n,int pinLed[]) 
{
	for (i=0;i<=9;i++)
	{
 		digitalWrite(pinLed[i],HIGH);
  		delay(BPM);
	}
	for (i=9; i>=0 ;i--)
	{
  		digitalWrite(pinLed[i],LOW);
  		delay(BPM);
	}
}

void coeur_sapin(int i,int n,int pinLed[]) 
{
  	for (i=0; i<=9 ;i +=2 )
	{
 		digitalWrite(pinLed[i],HIGH);
 		digitalWrite(pinLed[i+1],LOW);
	}
	delay(BPM);

  	for (i=0; i<=9 ;i +=2 )
	{
 		digitalWrite(pinLed[i],LOW);
 		digitalWrite(pinLed[i+1],HIGH);
	}
	delay(BPM);
}


