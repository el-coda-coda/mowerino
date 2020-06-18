#include <Servo.h>

#define ESC_ATTACH  11
#define ESC_OFF 1000
#define ESC_ON 1300 //ESC ON PUO' ANDARE DA 1000 A 2000
int ON_OFF = 1;
int  ON_OFF_ESC_PIN = BUTTON_PIN;

Servo esc;

void setup_esc ()
{
    delay(1000);
    esc.writeMicroseconds(1000);
    delay(5000);
    esc.writeMicroseconds(1300);
    delay(3000);
    esc.writeMicroseconds(1000);
}

void esc_on()
{
    esc.writeMicroseconds(ESC_ON);
}

void esc_off()
{
    esc.writeMicroseconds(ESC_OFF);
}

void esc_botton_control()
{
    if(digitalRead(ON_OFF_ESC_PIN) ==HIGH)
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