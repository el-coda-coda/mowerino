#include "ultrasonic.h"
#include "curves_control.h"

#include "constants.h"
#include "engines.h"
#include "segments.h"
#include "esc_control.h"

int curving = 0;
int movement_return;
int lenght_go_back = 0;

void setup ()
{

   // LiquidCrystal_I2C lcd(0x27,20,4);
   // lcd.init();
   // lcd.backlight();
   
   esc_setup();
   delay(3000);
   engines_stop();
   Serial.begin(9600);
   /*Serial.println(distance(trig1, echo1));*/
   pinMode(ULTRASONIC_ECHO_PIN_1, INPUT);
   pinMode(ULTRASONIC_TRIGGER_PIN_1, OUTPUT);
   pinMode(ULTRASONIC_ECHO_PIN_2, INPUT);
   pinMode(ULTRASONIC_TRIGGER_PIN_2, OUTPUT); 
   pinMode(pwm_A, OUTPUT);
   pinMode(dir_A, OUTPUT);
   pinMode(pwm_B, OUTPUT);
   pinMode(dir_B, OUTPUT);
   pinMode(BUTTON_PIN, INPUT);
   pinMode(13, OUTPUT);
}


void loop ()
{

   /*
   delay(1000);
   logDebug(String("Engines go forward"));

   curving = go_forward(200); 
   logDebug(String("The curve type is: ") + String(curving));
   if (curving == GO_BACK)
   {
      lenght_go_back = curve_back();
      logDebug(String("GO BACK: ") + String(lenght_go_back) + String("cm"));
      movement_return = go_back(lenght_go_back);
   }
   if (curving == CURVE_RIGHT) 
   {
      movement_return = turn_right90();
   }
   if (curving == CURVE_LEFT)
   {
      movement_return = turn_left90();
   }
   if (curving == TURN_180) 
   {
      movement_return = turn_right180();
   }
   if(movement_return == MOVEMENT_OK)  
   {
      logDebug(String("Movement return: MOVEMENT OK"));
   }
   */

   go_back(200);
   
   
}
