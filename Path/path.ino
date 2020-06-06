#include "rettangolo.h"


void setup() 
{

  lcd.begin(16,4); 
  lcd.backlight();
  setup_motori(pin_1, pin_apwm, pin_2, pin_3, pin_bpwm, pin_4);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);

}

void loop() 
{

  rettangolo(latoA, latoB);

}

void setup_motori (int pin1, int pinapwm, int pin2, int pin3, int pinbpwm, int pin4)
{
  
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pinapwm, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pinbpwm, OUTPUT);

}
