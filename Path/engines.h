#include "ultrasonic.h"

#define ENGINE_MAX 255
#define ENGINE_DELAY 1000
#define ULTRASONIC_QUERY_TIME 1000 //everysecond
#define ENGINE_STEP_DELAY 500 //Delay per ogni step di motore

#define MOVEMENT_OK 0
#define MOVEMENT_OBSTACLE_FOUND -10
#define MOVEMENT_GENERIC_ERROR -1

#define MOVEMENT_OBSTACLE_DISTANCE 20 //distance treshold (cm) to block current movement


//motor A
#define DIRECTION_PIN_ENGINE_A  2
#define PWM_PIN_ENGINE_A  6

//motor B
#define DIRECTION_PIN_ENGINE_B  12
#define PWM_PIN_ENGINE_B  10


//Delay on engine movement
void engines_delay() {
  delay(ENGINE_DELAY);
}


//Set the engines power, integer value from 0 to 255
void engines(int right_power, int left_power)
{

  if(right_power >= 0)
  {

    analogWrite(PWM_PIN_ENGINE_A, right_power);
    digitalWrite(DIRECTION_PIN_ENGINE_A, LOW);

  }
  if(right_power < 0)
  {

    analogWrite(PWM_PIN_ENGINE_A, (right_power*-1));
    digitalWrite(DIRECTION_PIN_ENGINE_A, HIGH);

  }
  if(left_power >= 0)
  {

    analogWrite(PWM_PIN_ENGINE_B, left_power);
    digitalWrite(PWM_PIN_ENGINE_B, LOW);

  }
  if(left_power < 0)
  {

    analogWrite(PWM_PIN_ENGINE_B, (left_power*-1));
    digitalWrite(PWM_PIN_ENGINE_B, HIGH);


  }
  
}


//Moves left at max power for <duration> seconds
int engines_movement(float duration, int power_right, int power_left) {
   Serial.println("engine movement");
   int duration_millseconds = (int)(duration * 1000);
   int curr_time =0;
   bool obstacle_found = false;
   while ((curr_time < duration_millseconds) && !obstacle_found)
   {
      engines(power_right, power_left);
      delay(ENGINE_STEP_DELAY);
      curr_time = curr_time + ENGINE_STEP_DELAY;

      //Check ultrasensor every ULTRASONIC_QUERY_TIME millisecs doing division module
      int division_mod = curr_time % ULTRASONIC_QUERY_TIME;
      if (division_mod == 0) {
        int obstacle_distance = get_obstacle_distance(ULTRASONIC1_TRIGGER_PIN,ULTRASONIC1_ECHO_PIN);
        obstacle_found = (obstacle_distance < MOVEMENT_OBSTACLE_DISTANCE);
      }
   }
   if (obstacle_found) {
     return MOVEMENT_OBSTACLE_FOUND;
   }
   else
    return MOVEMENT_OK;
}



//Moves left at max power for <duration> seconds
int engines_left(float duration) {
   return engines_movement(duration,0,ENGINE_MAX); 
}

//Moves right at max power
int engines_right(float duration) {
   return engines_movement(duration,ENGINE_MAX,0);
}


//Moves back at max power
int engines_back(float duration) {
  return engines_movement(duration,-ENGINE_MAX, -ENGINE_MAX);
}

//Moves forward at max power
int engines_forward(float duration) {
  return engines_movement(duration,ENGINE_MAX, ENGINE_MAX);
}


//Stop each engine
int engines_stop() {
  engines(0,0);
  return 0;
}
