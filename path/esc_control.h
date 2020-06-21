#include <Servo.h>

#define ESC_ATTACH  3
#define ESC_OFF 1000
#define ESC_ON 1300 //ESC ON PUO' ANDARE DA 1000 A 2000
int ON_OFF = 1;
int  ON_OFF_ESC_PIN = BUTTON_PIN;

Servo esc;

void esc_on()
{
    esc.writeMicroseconds(ESC_ON);
}

void esc_off()
{
    esc.writeMicroseconds(ESC_OFF);
}

void esc_botton_toggle()
{
    if(digitalRead(ON_OFF_ESC_PIN) == HIGH)
    {
        ON_OFF = ON_OFF * -1;
    }
    if(ON_OFF < 0)
    {
        esc_on();
    }
    else
    {
        esc_off();
    }
    
}


void esc_setup ()
{
    esc.attach(ESC_ATTACH);
    //ESC setup for starting up.
    delay(1000);
    esc_off();
    delay(5000);
    esc_on();
    delay(3000);
    esc_off();
}