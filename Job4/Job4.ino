#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int bouton = 2;

unsigned long temps_affichage = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Yousry Theo");
  pinMode(bouton, INPUT);
}

void loop() {
  int etat_bouton = digitalRead(bouton);
  if (etat_bouton == HIGH) {
    temps_affichage = 0;
  }
  //Afficher le temps d'affichage sur la deuxième ligne
  lcd.setCursor(0, 1);
  lcd.print("Temps: ");
  lcd.print(temps_affichage / 500);
  lcd.print(" s");
  temps_affichage += 1;
  delay(1);
}
