#include "cardio.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Appelle la fonction qui récolte et calcule les données.
  recolteInformations();
}