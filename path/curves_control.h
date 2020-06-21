#define CURVE_RIGHT 90
#define CURVE_LEFT -90
#define TURN_180 180
#define RANGE_US_ERROR 5

#define MOVEMENT_OBSTACLE_DISTANCE 55 //distance treshold (cm) to block current movement
#define MOVMENT_DISTANCE_GO_BACK 50
#define MOVEMENT_OK 0
#define GO_BACK -255

long curve_RL ()
{
    delay(50);
    int left_US = get_obstacle_distance(ULTRASONIC_TRIGGER_PIN_2, ULTRASONIC_ECHO_PIN_2);
    delay(50);
    int right_US = get_obstacle_distance(ULTRASONIC_TRIGGER_PIN_1, ULTRASONIC_ECHO_PIN_1);
    if (right_US < MOVEMENT_OBSTACLE_DISTANCE || left_US < MOVEMENT_OBSTACLE_DISTANCE)
    {
        if (right_US < MOVMENT_DISTANCE_GO_BACK || left_US < MOVMENT_DISTANCE_GO_BACK)
        {
            logDebug(String("GO BACK, distance right: ") + String(right_US) + String(" cm, distance left: ") + String(left_US) + String(" cm"));

            return GO_BACK;
        }
        if ((left_US - RANGE_US_ERROR) < right_US  && right_US < (left_US + RANGE_US_ERROR))
        {
            logDebug(String("TURN 180°, distance right: ") + String(right_US) + String(" cm, distance left: ") + String(left_US) + String(" cm"));
            return(TURN_180);
        }
        else
        {
            if(right_US > left_US)
            {
                logDebug(String("TURN RIGHT 90°, distance right: ") + String(right_US) + String(" cm, distance left: ") + String(left_US) + String(" cm"));
                return (CURVE_RIGHT);
            }
            if (right_US < left_US)
            {
                logDebug(String("TURN LEFT 90°, distance right: ") + String(right_US) + String(" cm, distance left: ") + String(left_US) + String(" cm"));
                return(CURVE_LEFT);
            }
        }
    }
    else
    {
        logDebug(String("No obstacle founds"));
        return MOVEMENT_OK;
    }
}

long curve_back ()
{    
    delay(50);
    int right_US = get_obstacle_distance(ULTRASONIC_TRIGGER_PIN_1, ULTRASONIC_ECHO_PIN_1);
    delay(50);
    int left_US = get_obstacle_distance(ULTRASONIC_TRIGGER_PIN_2, ULTRASONIC_ECHO_PIN_2);
    if (right_US <= MOVMENT_DISTANCE_GO_BACK || left_US <= MOVMENT_DISTANCE_GO_BACK)
    {
        if (right_US < left_US)
        {
            logDebug(String("bebug curve back ") + String(right_US));
            logDebug(String("go back of: ") + String(MOVEMENT_OBSTACLE_DISTANCE - right_US));
            return (MOVEMENT_OBSTACLE_DISTANCE - right_US);
        }
        if (right_US > left_US)
        {
            logDebug(String("bebug curve back ") + String(right_US));
            logDebug(String("go back of: ") + String(MOVEMENT_OBSTACLE_DISTANCE - left_US));            
            return (MOVEMENT_OBSTACLE_DISTANCE - left_US);
        }
    }
}