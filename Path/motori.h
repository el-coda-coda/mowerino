#include "configurazione.h"

void motori(int destro, int sinistro)
{

  if(destro >= 0)
  {

    analogWrite(pin_apwm, destro);
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, LOW);

  }
  if(destro < 0)
  {

    analogWrite(pin_apwm, (destro*-1));
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, HIGH);

  }
  if(sinistro >= 0)
  {

    analogWrite(pin_bpwm, sinistro);
    digitalWrite(pin_3, HIGH);
    digitalWrite(pin_4, LOW);

  }
  if(sinistro < 0)
  {

    analogWrite(pin_bpwm, (sinistro*-1));
    digitalWrite(pin_3, LOW);
    digitalWrite(pin_4, HIGH);


  }
  

}