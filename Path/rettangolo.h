#include "distanza.h"
#include "calcolo_misure.h"
#include "motori.h"
#include "schermo.h"

void rettangolo (int l, int h)
{

    for (h; h >=14; h -15)
    {
        
        int percorso_fatto_L = l;
        printer( "", percorso_fatto_L, ultrasuoni(trig1, echo1, 1));
        
        if (ultrasuoni(trig1, echo1, 1) >= distanza_curva)
        {          
            for (percorso_fatto_L; percorso_fatto_L >= 0; percorso_fatto_L --)
            {
                motori(255, 255);
                calcolo_misure(7, rps, 1);
                printer( "", percorso_fatto_L, ultrasuoni(trig1, echo1, 1));
                lcd.setCursor(0,0);
                lcd.print("avanti");
            }           
        }
        else
        {
            lcd.setCursor(0,0);
            lcd.print("fermo");
            percorso_fatto_L = 0; // qua bisogna vedere se si riesce a fare una cosa che supera l'ostacolo tenendo conto di quanto va avanti
        }
                
        lcd.setCursor(0,0);
        lcd.print("giro");
        motori(255, -10);
        calcolo_misure(7, rps, spazio_curva);
        motori(-255, -255);
        calcolo_misure(7, rps, 5);
        motori(255, -10);
        calcolo_misure(7, rps, spazio_curva);

    }

}