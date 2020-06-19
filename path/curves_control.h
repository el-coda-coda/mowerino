#define CURVE_RIGHT 90
#define CURVE_LEFT -90
#define TURN_180 180
#define RANGE_US_ERROR 5

#define MOVEMENT_OBSTACLE_DISTANCE 40 //distance treshold (cm) to block current movement
#define MOVEMENT_OK 0

long curve_RL ()
{
    // int right_US = get_obstacle_distance(ULTRASONIC1_TRIGGER_PIN, ULTRASONIC1_ECHO_PIN);
    // int left_US = get_obstacle_distance(ULTRASONIC2_TRIGGER_PIN, ULTRASONIC2_ECHO_PIN);
    int right_US = 100;
    int left_US = 100;

    if (right_US < MOVEMENT_OBSTACLE_DISTANCE || left_US < MOVEMENT_OBSTACLE_DISTANCE)
    {
        if ((left_US - RANGE_US_ERROR) < right_US  && right_US < (left_US + RANGE_US_ERROR))
        {
            logDebug(String("TURN 180°, distance right: ") + String(right_US) + String(" cm, distance left: ") + String(left_US) + String(" cm"));
            return(TURN_180);
        }
        else
        {
            if(right_US < left_US)
            {
                logDebug(String("TURN RIGHT 90°, distance right: ") + String(right_US) + String(" cm, distance left: ") + String(left_US) + String(" cm"));
                return (CURVE_RIGHT);
            }
            if (right_US > left_US)
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
