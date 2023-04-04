#include "LiquidCrystal.h" 
LiquidCrystal lcd(7,8,9,10,11,12);

int heures,minutes,secondes;
char message[16] = "";

void setup()
{
    lcd.begin(16, 2);


    heures = 0;
    minutes = 0;
    secondes = 0;
}

void loop()
{
  
    if(secondes == 60)
    {
        secondes = 0;
        minutes++;
    }
    if(minutes == 60) 
    {
        minutes = 0;
        heures++;
    }
    if(heures == 24) //
    {
        heures = 0;
    }

    sprintf(message,"Il est %2d:%2d:%2d",heures,minutes,secondes);

    lcd.home();           

    lcd.write(message);   

    delay(1000);
  
    secondes++;
}