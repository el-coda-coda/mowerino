#include "ultrasonic.h"
#include "curves_control.h"

#include "constants.h"
#include "engines.h"
#include "segments.h"
#include "esc_control.h"

int curving = 0;

void setup ()
{

   // LiquidCrystal_I2C lcd(0x27,20,4);
   // lcd.init();
   // lcd.backlight();
   
  // esc_setup();
   delay(3000);
   engines_stop();
   Serial.begin(9600);
   /*Serial.println(distance(trig1, echo1));*/
   pinMode(ULTRASONIC1_TRIGGER_PIN, OUTPUT);
   pinMode(ULTRASONIC1_ECHO_PIN, INPUT);
   pinMode(pwm_A, OUTPUT);
   pinMode(dir_A, OUTPUT);
   pinMode(pwm_B, OUTPUT);
   pinMode(dir_B, OUTPUT);
   pinMode(BUTTON_PIN, INPUT);
   pinMode(13, OUTPUT);

   /*Testing percorsi semplici*/
   Serial.println("go forward 200");
   
   curving = go_forward(200); 
   logDebug(String("The curve type is: ") + String(curving));
   if (curving == CURVE_RIGHT) 
   {
      turn_right90;
   }
   if (curving == CURVE_LEFT)
   {
      turn_left90;
   }
   if (curving == TURN_180) 
   {
      turn_right180;
   }

}


void loop ()
{
   

}
