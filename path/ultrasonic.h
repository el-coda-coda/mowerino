#include "logging.h"
//Ultrasonic constant to compute obstacle distance
#define ULTRASONIC_PARAMETER 0.034

// Ultrasonic does not sense any obstacle (too far or too close)
#define ULTRASONIC_OUTOFRANGE 38000

//First ultrasonic sensor PINS
#define ULTRASONIC_ECHO_PIN_1  4
#define ULTRASONIC_TRIGGER_PIN_1  5

//Second ultrasonic sensor PINS
#define ULTRASONIC_ECHO_PIN_2  11
#define ULTRASONIC_TRIGGER_PIN_2  10

#define ULTRASONIC_ENABLED true
#define VERY_LONG_DINSTANCE 1000

//Computes distance from obstacle in centimeters
//Argumnents trigger_pin and echo_pin on arduino for ultrasonic sensor
long get_obstacle_distance(int trigger_pin, int echo_pin)
{
    //logDebug(String("Start US"));
    
    digitalWrite(trigger_pin, LOW);
    digitalWrite(trigger_pin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);
    //logDebug(String("50 ms delay"));

    long rotation = pulseIn(echo_pin, HIGH);  
    //logDebug(String("ROTATION: ") + String(rotation));  
    
    // if  (rotation == 0) {
    //     Serial.println("MAX: resetting sensor");
    //     pinMode(echo_pin, OUTPUT);
    //     delay(150);
    //     digitalWrite(echo_pin, LOW);
    //     delay(150);
    //     pinMode(echo_pin, INPUT);
    //     delay(150);
    //     rotation = pulseIn(echo_pin, HIGH);  
    //     logDebug(String("Rotation after reset: "));
    // }

    long distance = ULTRASONIC_PARAMETER * rotation / 2;  
    //logDebug(String("DISTANCE: ") + String(distance));  
    if ((rotation > ULTRASONIC_OUTOFRANGE) || !ULTRASONIC_ENABLED)
    {
        logDebug(String("End US, distance (cm): out of range"));
        return VERY_LONG_DINSTANCE;
    }
    else
    {
        //logDebug(String("End US") + String(distance));
        return distance; 
    }
}
