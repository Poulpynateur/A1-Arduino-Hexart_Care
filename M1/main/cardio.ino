#include <Arduino.h>
#include "cardio.h"

int valeurPrecedente = 0;
long tempsPrecedent = 0;

void recolteInformations() {
  int valeurActuelle;
  //On d�finit la valeur de d�tection d'un battement de coeur.
  int valeurSeuil = 650;
  long tempsDetection;
  //On collecte en temps r�el les informations envoy�es par le pince doigt.
  valeurActuelle = analogRead(0);
  
  //On v�rifie si un battement de coeur est d�tect�.
  if (valeurActuelle > valeurSeuil) {
    //On d�termine le d�but du battement de coeur.
    if (valeurPrecedente <= valeurSeuil) {
      tempsDetection = millis();
      //On v�rifie qu'il ne s'agit pas seulement d'un bruit parasite.
      if (tempsDetection > ((tempsPrecedent) + 200)) {
        //On envoie au moniteur s�rie la valeur du pouls en battement par minute.
        Serial.println( (1000.0 * 60.0) / (tempsDetection - tempsPrecedent),0);
        tempsPrecedent = tempsDetection;
      }
    }
  }
  valeurPrecedente = valeurActuelle;
}
