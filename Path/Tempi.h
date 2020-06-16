
void calcolo_misure(int d, float tempo_giro, float distanza_da_percorrere)
{

  float c = d * 3.14;
  float numero_giri = distanza_da_percorrere / c;
  float tempo = numero_giri / tempo_giro;
  delay(tempo * 1000);

}