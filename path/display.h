#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

bool lcd_initialized = false;

void setupLCD() {
    if (!lcd_initialized) {
        lcd.init();
        lcd.backlight();
        lcd_initialized = true;
    }
}


void display_print(int row, String message) {
    setupLCD();
    lcd.setCursor(0,row);
    lcd.print(message);
}

