#include <Arduino.h>
#include "cardio.h"

int valeurPrecedente = 0;
long tempsPrecedent = 0;

void recolteInformations() {
  int valeurActuelle;
  //On définit la valeur de détection d'un battement de coeur.
  int valeurSeuil = 650;
  long tempsDetection;
  //On collecte en temps réel les informations envoyées par le pince doigt.
  valeurActuelle = analogRead(0);
  
  //On vérifie si un battement de coeur est détecté.
  if (valeurActuelle > valeurSeuil) {
    //On détermine le début du battement de coeur.
    if (valeurPrecedente <= valeurSeuil) {
      tempsDetection = millis();
      //On vérifie qu'il ne s'agit pas seulement d'un bruit parasite.
      if (tempsDetection > ((tempsPrecedent) + 200)) {
        //On envoie au moniteur série la valeur du pouls en battement par minute.
        Serial.println( (1000.0 * 60.0) / (tempsDetection - tempsPrecedent),0);
        tempsPrecedent = tempsDetection;
      }
    }
  }
  valeurPrecedente = valeurActuelle;
}
