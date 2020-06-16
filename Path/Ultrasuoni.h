long distanza (int trig, int echo)
{

    digitalWrite(trig, LOW);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long durata = pulseIn(echo, HIGH);
    long distanza = 0.034 * durata / 2;

    if (durata > 38000)
    {
        return 100;
        distanza = -1;
    }
    else
    {
        return distanza;
    }

}