
void calcolo_misure(int d, float tempo_giro, int distanza_da_percorrere)
{

  float c = d * 3.14;
  float giro = tempo_giro *1000;
  float numero_giri = distanza_da_percorrere / c;
  delay(giro * numero_giri);

}