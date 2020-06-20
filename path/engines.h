#define ENGINE_MAX 255 //33 rpm a vuoto

#define ENGINE_DELAY 1000
//#define ULTRASONIC_QUERY_TIME 400 everysecond
#define ENGINE_STEP_DELAY 50 //Delay per ogni step di motore

#define MOVEMENT_OBSTACLE_FOUND -10
#define MOVEMENT_GENERIC_ERROR -1
#define US_DELAY 100

//motor A
#define DIRECTION_PIN_ENGINE_A  2
#define PWM_PIN_ENGINE_A  5

//motor B
#define DIRECTION_PIN_ENGINE_B  12
#define PWM_PIN_ENGINE_B  10

int us_query = 0;




//Delay on engine movement
void engines_delay() {
  delay(ENGINE_DELAY);
}


//Set the engines power, integer value from 0 to 255
void engines(int left_power, int right_power)
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
    digitalWrite(DIRECTION_PIN_ENGINE_B, LOW);

  }
  if(left_power < 0)
  {

    analogWrite(PWM_PIN_ENGINE_B, (left_power*-1));
    digitalWrite(DIRECTION_PIN_ENGINE_B, HIGH);


  }
  
}

//Stop each engine
int engines_stop() 
{
  engines(0,0);
  return 0;
}


//Moves left at max power for <duration> seconds
int engines_movement_controlled(float duration, int power_left, int power_right) {
   
   logDebug(String("engines go"));
   engines(power_left, power_right);
   
   int duration_millseconds = (int)(duration * 1000);
   int curr_time =0;
   int movement_result = 0;
   
   logDebug(String("duration (sec): ") + String(duration));
   logDebug(String("duration (ms): ") + String(duration_millseconds));

   while ((curr_time < duration_millseconds) && movement_result == 0)
   {
      logDebug(String(curr_time));
      if (us_query == 2) 
      {
        movement_result = curve_RL();
        us_query = 0;     
      }
      //tempo medio impiegato dal check ultrasuoni
      curr_time = curr_time + US_DELAY;
      us_query ++;
      //idea per controllare la posizione in futuro
      //float lenght_percurred = map(curr_time, 0, duration_millseconds, 0, lenght); questo sarebe interessante per determinare la posizione del robot, bisognerebbe trovare il modo di dargli la lunghezza che deve percorrere
   }
    engines(0,0);
  if (!movement_result == 0 ) 
  {
    logDebug(String("engines stop"));
  }
return movement_result;
}

int engines_movement(float duration, int power_left, int power_right) {
   
   logDebug(String("engines go"));
   engines(power_left, power_right);
   
   int duration_millseconds = (int)(duration * 1000);
   int curr_time =0;
   int movement_result = 0;
   
   logDebug(String("duration (sec): ") + String(duration));
   logDebug(String("duration (ms): ") + String(duration_millseconds));

  while ((curr_time < duration_millseconds) && movement_result == 0)
  {
      logDebug(String(curr_time));
      delay(ENGINE_STEP_DELAY);
      curr_time = curr_time + ENGINE_STEP_DELAY;
      
  }
    engines(0,0);
  
  if (!movement_result == 0 ) 
  {
    logDebug(String("engines stop"));
  }
return movement_result;
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
  return engines_movement_controlled(duration,ENGINE_MAX, ENGINE_MAX);
}



      //Check ultrasensor every ULTRASONIC_QUERY_TIME millisecs doing division module
      //int division_mod = (curr_time) % ULTRASONIC_QUERY_TIME;
      
      // if (division_mod == 0) 
      // {
      //   Serial.println("esisto ancora3");
      //   obstacle_distance = get_obstacle_distance(ULTRASONIC1_TRIGGER_PIN,ULTRASONIC1_ECHO_PIN);
      //   Serial.println(obstacle_distance);
      //   // obstacle_found = (obstacle_distance < MOVEMENT_OBSTACLE_DISTANCE);
      //   obstacle_found = (10 < 20);
      //   Serial.println(obstacle_found);
      // }