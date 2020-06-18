
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

    Serial.println("START US");
    digitalWrite(trigger_pin, LOW);
    Serial.println("step1 US");
    digitalWrite(trigger_pin, HIGH);
    Serial.println("step2 US");
    
    delayMicroseconds(10);
    Serial.println("step3 US");
    
    digitalWrite(trigger_pin, LOW);
    Serial.println("step4 US");

    long rotation = pulseIn(echo_pin, HIGH);  
    Serial.println("step5 US");
    
    long distance = ULTRASONIC_PARAMETER * rotation / 2;
    Serial.println("step6 US");
    

    Serial.println("STOP US");
    if ((rotation > ULTRASONIC_OUTOFRANGE) || !ULTRASONIC_ENABLED)
    {
        //gli ultrasuoni non vedono nulla  o sono disabilitati
        //Serial.println("No obstacles in front of me");
        return VERY_LONG_DINSTANCE;
    }
    else
    {
        return distance;
    }

}
