#include "logging.h"
//Ultrasonic constant to compute obstacle distance
#define ULTRASONIC_PARAMETER 0.034

// Ultrasonic does not sense any obstacle (too far or too close)
#define ULTRASONIC_OUTOFRANGE 38000

//First ultrasonic sensor PINS
#define ULTRASONIC1_ECHO_PIN  3
#define ULTRASONIC1_TRIGGER_PIN  4

//Second ultrasonic sensor PINS
#define ULTRASONIC2_ECHO_PIN  7
#define ULTRASONIC2_TRIGGER_PIN  6

#define ULTRASONIC_ENABLED true
#define VERY_LONG_DINSTANCE 1000


//Computes distance from obstacle in centimeters
//Argumnents trigger_pin and echo_pin on arduino for ultrasonic sensor
long get_obstacle_distance(int trigger_pin, int echo_pin)
{
    logDebug(String("Start US"));
    
    digitalWrite(trigger_pin, LOW);
    digitalWrite(trigger_pin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);
    logDebug(String("50 ms delay"));
    long rotation = pulseIn(echo_pin, HIGH);  
    long distance = ULTRASONIC_PARAMETER * rotation / 2;    
    if ((rotation > ULTRASONIC_OUTOFRANGE) || !ULTRASONIC_ENABLED)
    {
        logDebug(String("End US, distance (cm): out of range"));
        return VERY_LONG_DINSTANCE;
    }
    else
    {
        logDebug(String("End US"));
        return distance; 
    }
}
