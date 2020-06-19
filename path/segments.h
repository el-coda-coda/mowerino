//wheel diameter in centimeters
#define WHEEL_DIAMETER 12
#define RPM 30

#define distanza_curva  20



//Solo questa classe lo può utilizzare
float segment_time(int wheel_diamater,float segment_length)
{
  float rps = ((float) RPM) / 60;
  


  float circumference = wheel_diamater * 3.14;
  logDebug("Circumference: ",circumference);

  float rotation_number = segment_length / circumference;
  logDebug("rotation_number: ",rotation_number);
  
  float segment_time_result = rotation_number / rps;
  logDebug("segment_time_result: ",segment_time_result);
  return segment_time_result;

}


int go_forward(float segment_length) 
{
  int movement_result=0;
  float seg_time = segment_time(WHEEL_DIAMETER, segment_length);
  
  logDebug(String("Go forwardo for time (sec) ") + String(seg_time));
  logDebug(String("Segment length (cm): ") + String(segment_length));

  movement_result = engines_forward(seg_time);
  if (movement_result == MOVEMENT_OBSTACLE_FOUND || movement_result == MOVEMENT_GENERIC_ERROR) 
  {
    engines_stop(); //per ora spengo
    if (movement_result == MOVEMENT_OBSTACLE_FOUND) 
    {
      logDebug(String("obstacle found"));
    }
    if (movement_result == MOVEMENT_GENERIC_ERROR) 
    {
      logDebug(String("generic movement error"));
    }
  }
  return movement_result;
}


int turn_right90(float segment_length) {
  int movement_result=0;
  
  float seg_time = segment_time((int)WHEEL_DIAMETER, (float)segment_length);
  movement_result=engines_right(seg_time);
  
  if (movement_result<0) engines_stop(); //per ora spengo
  return movement_result;
  
}

int turn_left90(float segment_length) {
  int movement_result=0;
  
  float seg_time = segment_time((int)WHEEL_DIAMETER, (float)segment_length);
  movement_result = engines_left(seg_time);
  
  if (movement_result<0) engines_stop(); //per ora spengo
  return movement_result;
}

int turn_right180(float segment_length) {
  int movement_result=0;

  movement_result=turn_right90(segment_length);
  if (movement_result<0) { 
    engines_stop(); //per ora spengo
    return movement_result;
  }
  
  movement_result=turn_right90(segment_length);
  if (movement_result<0) { 
    engines_stop(); //per ora spengo
    return movement_result;
  }
  return movement_result;
}


int turn_left180(float segment_length) {
  int movement_result=0;
  
  movement_result=turn_left90(segment_length);
  if (movement_result<0) { 
    engines_stop(); //per ora spengo
    return movement_result;
  }
  
  movement_result = turn_left90(segment_length);
  if (movement_result<0) { 
    engines_stop(); //per ora spengo
    return movement_result;
  }
  return movement_result;
}





int go_back(float segment_length) {
  int movement_result=0;
  float seg_time = segment_time(WHEEL_DIAMETER, segment_length);
  movement_result = engines_back(seg_time);
  if (movement_result<0) engines_stop(); //per ora spengo
  return movement_result;
}

 
