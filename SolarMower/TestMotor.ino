/*
  SolarMower Arduino testMotor
  motor DX forward and reverse
  motor SX forward and reverse
  PEN for exit test
 */

void testMotor()
{
  clearLCD();
  lcdPosition(0,0);
  LCD.println("Test motor");
  Serial.println("Motor DX forward...");  
  lcdPosition(1,0);  
  LCD.println("Motor DX forward");  
  digitalWrite(DIRA_pin, LOW); 
  for (i=0; i<=255; i++)
  {
     analogWrite(PWMA_pin, i);
     delay(5);
  }  
  delay(2000);
  for (i=255; i>=0; i--)
  {
     analogWrite(PWMA_pin, i);
     delay(5);
  } 
  delay(1000);  
  Serial.println("Motor DX reverse..."); 
  lcdPosition(1,0);  
  LCD.println("Motor DX reverse");   
  digitalWrite(DIRA_pin, HIGH); 
  for (i=0; i<=255; i++)
  {
     analogWrite(PWMA_pin, i);
     delay(5);
  }  
  delay(2000);
  for (i=255; i>=0; i--)
  {
     analogWrite(PWMA_pin, i);
     delay(5);
  } 
  delay(1000); 
  Serial.println("Motor SX forward...");  
  lcdPosition(1,0);
  LCD.println("Motor SX forward");  
  digitalWrite(DIRB_pin, LOW); 
  for (i=0; i<=255; i++)
  {
     analogWrite(PWMB_pin, i);
     delay(5);
  }  
  delay(2000);
  for (i=255; i>=0; i--)
  {
     analogWrite(PWMB_pin, i);
     delay(5);
  } 
  delay(1000);  
  Serial.println("Motor SX reverse..."); 
  lcdPosition(1,0);  
  LCD.println("Motor SX reverse");  
  digitalWrite(DIRB_pin, HIGH); 
  for (i=0; i<=255; i++)
  {
     analogWrite(PWMB_pin, i);
     delay(5);
  }  
  delay(2000);
  for (i=255; i>=0; i--)
  {
     analogWrite(PWMB_pin, i);
     delay(5);
  } 
  Serial.println();
  delay(1000);   
}  
