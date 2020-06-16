void motori(int destro, int sinistro)
{

  if(destro >= 0)
  {

    analogWrite(pwm_A, destro);
    digitalWrite(dir_A, HIGH);

  }
  if(destro < 0)
  {

    analogWrite(pwm_A, (destro*-1));
    digitalWrite(dir_A, LOW);

  }
  if(sinistro >= 0)
  {

    analogWrite(pwm_B, sinistro);
    digitalWrite(dir_B, HIGH);

  }
  if(sinistro < 0)
  {

    analogWrite(pwm_B, (sinistro*-1));
    digitalWrite(dir_B, LOW);


  }
  
}