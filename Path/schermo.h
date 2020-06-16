#include <jm_Wire.h>

#include <jm_Scheduler.h>
 
#include <LiquidCrystal_I2C.h> // Using version 1.2.1

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  


void printer (int valore,  int valore2, int valore3)
{
  lcd.setCursor(0,0);
  //lcd.print("latoA");
  lcd.setCursor(0,1);
  //lcd.print(valore);
  lcd.setCursor(6,0);
  lcd.print("percorso fatto");
  lcd.setCursor(6,1);
  lcd.print(valore2);
  lcd.setCursor(4,3);
  lcd.print("ultrasuoni");
  lcd.setCursor(14,3);
  lcd.print(valore3);
}


 