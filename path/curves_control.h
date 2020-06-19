#define CURVE_RIGHT 90
#define CURVE_LEFT -90
#define TURN_180 180
#define RANGE_US_ERROR 5

long curve_RL ()
{
    int right_US = get_obstacle_distance(ULTRASONIC1_TRIGGER_PIN, ULTRASONIC1_ECHO_PIN);
    int left_US = get_obstacle_distance(ULTRASONIC2_TRIGGER_PIN, ULTRASONIC2_ECHO_PIN);
    if ((left_US - RANGE_US_ERROR) < right_US < (left_US + RANGE_US_ERROR))
    {
        return(TURN_180);
    }
    else
    {
        if(right_US < left_US)
        {
            return (CURVE_RIGHT);
        }
        if (right_US > left_US)
        {
            return(CURVE_LEFT);
        }
    }
}
