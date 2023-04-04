
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int pin_x = A0;
int pin_y = A1;

void setup() {

  lcd.begin(16, 2);
}

void loop() {
  int val_x = analogRead(pin_x);
  int val_y = analogRead(pin_y);

  String direction = "";
  if (val_x < 400) {
    direction = "Gauche";
  } else if (val_x > 600) {
    direction = "Droite";
  } else if (val_y < -400) {
    direction = "Haut";
  } else if (val_y > 600) {
    direction = "Bas";
  } else {
    direction = "Centre";
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Direction:");
  lcd.setCursor(0, 1);
  lcd.print(direction);

  delay(100);
}
