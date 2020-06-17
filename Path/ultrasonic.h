
//Ultrasonic constant to compute obstacle distance
#define ULTRASONIC_PARAMETER 0.034

// Ultrasonic does not sense any obstacle (too far or too close)
#define ULTRASONIC_OUTOFRANGE 38000

//First ultrasonic sensor PINS
#define ULTRASONIC1_ECHO_PIN  3
#define ULTRASONIC1_TRIGGER_PIN  4

#define ULTRASONIC_ENABLED false
#define VERY_LONG_DINSTANCE 1000


//Computes distance from obstacle in centimeters
//Argumnents trigger_pin and echo_pin on arduino for ultrasonic sensor
long get_obstacle_distance(int trigger_pin, int echo_pin)
{

    digitalWrite(trigger_pin, LOW);

    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    long rotation = pulseIn(echo_pin, HIGH);
    long distance = ULTRASONIC_PARAMETER * rotation / 2;

    if ((rotation > ULTRASONIC_OUTOFRANGE) || !ULTRASONIC_ENABLED)
    {
        //gli ultrasuoni non vedono nulla  o sono disabilitati
        return VERY_LONG_DINSTANCE;
    }
    else
    {
        return distance;
    }

}