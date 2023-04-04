#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
float tension;
void setup() {
  lcd.begin(16,2);
  lcd.clear();

}

void loop(){
  tension = analogRead(A0) * 5.0/1023.0;
  lcd.print(tension);
}
