#include "cardio.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Appelle la fonction qui r�colte et calcule les donn�es.
  recolteInformations();
}