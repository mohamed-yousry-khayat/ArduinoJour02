#include "LiquidCrystal.h"

LiquidCrystal lcd(7,8,9,10,11,12);

// caractère
byte smiley[8] = {
    B00000,
    B10001,
    B00000,
    B00000,
    B10001,
    B01110,
    B00000,
};

void setup() {
    lcd.createChar(0, smiley);
    lcd.begin(16, 2);
    lcd.write((uint8_t) 0); // affiche le caractère
}

void loop() {

}