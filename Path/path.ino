#include "rettangolo_1.h"

void setup ()
{

   delay(1000);
   motori(0,0);
   Serial.begin(9600);
   Serial.println(distanza(trig1, echo1));
   pinMode(trig1, OUTPUT);
   pinMode(echo1, INPUT);
   pinMode(pwm_A, OUTPUT);
   pinMode(dir_A, OUTPUT);
   pinMode(pwm_B, OUTPUT);
   pinMode(dir_B, OUTPUT);
   pinMode(bottone, INPUT);
   pinMode(13, OUTPUT);

}


void loop ()
{
   Serial.println(distanza(trig1, echo1));
   if(distanza(trig1, echo1)<= 20)
   {

      digitalWrite(13, HIGH);
    
   }
   else
   {

      digitalWrite(13, LOW);
    
   }
   rettangolo(latoA, latoB);

}
