#include "constants.h"
#include "engines.h"
#include "segments.h"



void setup ()
{

   delay(5000);
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
   
   go_forward(200); 


}


void loop ()
{
   

}
