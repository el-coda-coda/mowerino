//wheel diameter in centimeters
#define WHEEL_DIAMETER 12
#define RPM 30
#define CURVE_LENGHT 65.94

#define distanza_curva  20
#define ROBOT_LARGE 42



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


int turn_right90() {
  int movement_result=0;
  
  float seg_time = segment_time((int)WHEEL_DIAMETER, CURVE_LENGHT);
  movement_result=engines_right(seg_time);
  return movement_result;
  
}

int turn_left90() {
  int movement_result=0;
  
  float seg_time = segment_time((int)WHEEL_DIAMETER, CURVE_LENGHT);
  movement_result = engines_left(seg_time);
  return movement_result;
}

int turn_right_xx (int grade)
{
  int movement_result=0;
  int lenght_curve = (grade*(ROBOT_LARGE*6.28))/360; //grade / 360° = lenght_curve / (ROBOT_LARGE*6.28)
  float seg_time = segment_time((int)WHEEL_DIAMETER, lenght_curve);
  
  movement_result=engines_right(seg_time);
  return movement_result;
}

int turn_left_xx (int grade)
{
  int movement_result=0;
  int lenght_curve = (grade*(ROBOT_LARGE*6.28))/360; //grade / 360° = lenght_curve / (ROBOT_LARGE*6.28)
  float seg_time = segment_time((int)WHEEL_DIAMETER, lenght_curve);
  
  movement_result=engines_left(seg_time);
  return movement_result;
}

int turn_right180() {
  int movement_result=0;

  movement_result=turn_right_xx(180);
  return movement_result;
}


int turn_left180() {
  int movement_result=0;
  
  movement_result=turn_left_xx(180);
  return movement_result;
}

int go_back(float segment_length) {
  int movement_result=0;
  float seg_time = segment_time(WHEEL_DIAMETER, segment_length);
  movement_result = engines_back(seg_time);
  return movement_result;
}

 
int go_forward(float segment_length) 
{
  int movement_result=0;
  float seg_time = segment_time(WHEEL_DIAMETER, segment_length);

  logDebug(String("Go forward for time (sec) ") + String(seg_time));
  logDebug(String("Segment length (cm): ") + String(segment_length));

  movement_result = engines_forward(seg_time);

  if (movement_result != MOVEMENT_OK) 
  {
    //movement_result = engines_stop(); //per ora spengo
    if (movement_result == MOVEMENT_GENERIC_ERROR) 
    {
      logDebug(String("generic movement error"));
      movement_result = MOVEMENT_GENERIC_ERROR;
      engines_stop();        
    }
    if (movement_result == GO_BACK)
    {
      logDebug(String("GO BACK"));
      engines_stop();
      movement_result = GO_BACK; 
    }
    else
    {
      logDebug(String("obstacle found"));
    }
  }
  return movement_result;
}
