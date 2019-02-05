long randFrequence;

void setup() {
 Serial.begin(9600);
 randomSeed(analogRead(0));
}

void loop() {
  randFrequence = random(55,90);
  Serial.println(randFrequence);

  delay(1000);
}