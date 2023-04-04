#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int pourcentage = 0;

  while (pourcentage < 100) {
    lcd.clear();

    int nb_caracteres = pourcentage / 7;
    lcd.setCursor(0, 0);
    lcd.print("[");
    for (int i = 0; i < nb_caracteres; i++) {
      lcd.print("#");
    }
    for (int i = nb_caracteres; i < 14; i++) {
      lcd.print(" ");
    }
    lcd.print("]");


    lcd.setCursor(0, 1);
    lcd.print("Progression: ");
    lcd.print(pourcentage);
    lcd.print("%");

    pourcentage++;

    delay(100);
  }
}