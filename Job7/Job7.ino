//Inclusion de la bibliothèque pour l'afficheur LCD
#include <LiquidCrystal.h>

//Broche du bouton poussoir
const int bouton = 2;

//Initialisation de l'afficheur LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Variables pour stocker le temps
unsigned long temps_precedent = 0;
unsigned long temps_actuel;
unsigned long temps_ecoule = 0;

//Variable pour stocker l'état du chronomètre
int etat_bouton = false;
boolean chrono_actif = false;

void setup() {
  //Initialisation de l'afficheur LCD
  lcd.begin(16, 2);
  //Initialisation de la broche du bouton poussoir en entrée
  pinMode(bouton, INPUT);
}

void loop() {
  //Lecture de l'état du bouton poussoir
  etat_bouton = digitalRead(bouton);

  //Activation ou désactivation du chronomètre en fonction de l'état du bouton poussoir
  if (etat_bouton == HIGH && chrono_actif == false) {
    chrono_actif = true;
    temps_precedent = millis();
  } else if (etat_bouton == HIGH && chrono_actif == true) {
    chrono_actif = false;
  }

  //Affichage du temps écoulé sur l'afficheur LCD
  lcd.setCursor(0, 0);
  lcd.print("Temps ecoule: ");
  lcd.print(temps_ecoule / 1000);
  lcd.print(" s");

  //Si le chronomètre est actif, calcul du temps écoulé depuis le dernier changement d'état du bouton poussoir
  if (chrono_actif == true) {
    temps_actuel = millis();
    temps_ecoule += temps_actuel - temps_precedent;
    temps_precedent = temps_actuel;
  }

  //Attente de 100 millisecondes avant la prochaine itération de la boucle
  delay(100);
}

