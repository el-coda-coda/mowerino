/*
  SolarMower Arduino serialDebug
 */

void serialDebug()
{
  Serial.print("VBat= ");
  Serial.print(VBat);
  Serial.println(" V");

  Serial.print("IPanel= ");  
  Serial.print(IPanel);
  Serial.println(" A");
  
  Serial.print("ICut= ");
  Serial.print(ICut); 
  Serial.println(" A");
  
  Serial.print("BWFR count= ");
  Serial.println(BWFR_count);
  Serial.print("BWFL count= ");  
  Serial.println(BWFL_count);  
  Serial.print("US_DX=");
  Serial.print(US_DX.read());
  Serial.print("   US_SX=");
  Serial.println(US_SX.read());  
  
  Serial.println();
}  

void LCDdebug()
{
    clearLCD();
    lcdPosition(0,0);
    switch (mowerStatus)
    {
    case 0:
      LCD.print("CHARGE ");
      break;
    case 1:
      LCD.print("RUN    ");   
      break;
    case 2:
      LCD.print("STUCK  ");
      break;
    case 3:
      LCD.print("SEARCH ");  
      break;
    case 4:
      LCD.print("BATLOW ");  
      break;
    case 5:
      LCD.print("CHR RS ");
      break;
    case 6:
      LCD.print("CUT ER ");
      break;  
    }  
    
    LCD.print(VBatPC);
    LCD.print("%  ");
     
    lcdPosition(1,0);
    LCD.print("IC=");
    LCD.print(ICut);  
  
    lcdPosition(1,9);
    LCD.print("IP=");
    LCD.print(IPanel);     
} 
