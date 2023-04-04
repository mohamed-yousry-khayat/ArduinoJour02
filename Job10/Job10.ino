#include <LiquidCrystal.h>

// Initialise l'écran LCD avec les broches appropriées
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Initialise les broches pour le capteur de distance
const int trigPin = 2;
const int echoPin = 4;

void setup() {
  // Configure les broches du capteur de distance
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialise l'écran LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
}

void loop() {
  // Envoie un signal à ultrasons pour mesurer la distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lit la durée de l'écho pour calculer la distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Affiche la distance sur l'écran LCD
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(100);
}