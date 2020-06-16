#include "prima_di_tutto.h"
#include "Motori.h"
#include "Tempi.h"
#include "Ultrasuoni.h"

void destra90() {
  motori(MAXMOTORE, 0);
  calcolo_misure(DIAMETRORUOTA, rps, spazio_curva);
}


void sinistra90() {
  motori(0, MAXMOTORE);
  calcolo_misure(DIAMETRORUOTA, rps, spazio_curva);
}


void rettangolo (int base, int altezza)
{
    
    // Serial.print("Altezza: ");
    // Serial.println(altezza);
    int alt = altezza;
    int bas = base;    
    if(digitalRead(bottone) == HIGH)
    {
        delay(1000);

        int fgfg = -1;
        while ((alt - 15) >= -14)
        {
            x = 0;
            alt = alt -15;
            Serial.print("alt: ");
            Serial.println(alt);
            while ((distanza(trig1, echo1) >= distanza_curva) && (bas >= 0))
            {

                motori(255, 255);
                calcolo_misure(7, rps, 1);
                bas--;
                x++;
                Serial.print("x: ");
                Serial.println(x);

            }
            Serial.print("y: ");
            Serial.println(y);
            
            if(distanza(trig1, echo1)<= 20)
            {
              
            digitalWrite(13, HIGH);
                  
            }
            else
            {
              
                digitalWrite(13, LOW);
                  
            }
                            
            Serial.print("Allarme: ");
            Serial.println(altezza-y);
                
            if((15 > (altezza-y)) && ((altezza-y) > 0))
            {
             
             Serial.print("Allarme: ");
             Serial.println(altezza-y);
                
                if (fgfg < 0)
                {
                        
                    sinistra90();
                    motori(0,0);
                    delay(1000);
                    motori(-255, -255);
                    calcolo_misure(7, rps, (altezza-y));
                    motori(0,0);
                    delay(1000);
                    
                    sinistra90();
                    motori(0,0);
                    delay(1000);
                    fgfg = -1;

                }
                else
                {
                    destra90();
                    
                    motori(0,0);
                    delay(1000);
                    
                    motori(-255, -255);
                    calcolo_misure(7, rps, (altezza-y));
                    motori(0,0);
                    delay(1000);
                    destra90();
                    motori(0,0);
                    delay(1000);

                }
                y = altezza;

            }
            else
            {
            
                if (fgfg < 0)
                {
                        
                    sinistra90();
                    motori(0,0);
                    delay(1000);
                    motori(-255, -255);
                    calcolo_misure(7, rps, (18 - lama));
                    motori(0,0);
                    delay(1000);

                    sinistra90();
                    motori(0,0);
                    delay(1000);
                    fgfg = -1;

                }
                else
                {
                    destra90();
                    motori(0,0);
                    delay(1000);
                    motori(-255, -255);
                    calcolo_misure(7, rps, (18 - lama));
                    motori(0,0);
                    delay(1000);
                    destra90();
                    motori(0,0);
                    delay(1000);

                }
                y = y-(18-lama);

            }
            fgfg = fgfg * -1;
            bas = base;
            Serial.print("y: ");
            Serial.println(y);
            Serial.print("x: ");
            Serial.println(x);
            y = y+15;
                
        }
    
    }
    
}
