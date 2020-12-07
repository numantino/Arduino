#include "conf.h"
#include "controlRiego.hpp"

int i;
int inChar;

void setup()
{
    //Inicializacion logs
    Serial.begin(9600);
    //Inicializacion de resto de componentes
    iniYL69(SENSOR_YL69, MIN_HUMEDAD);
    iniRele(RELE_1,T_BOMBA);
    //
    i=0;
    Serial.println("Inicio control rele riego");
}

void loop()
{
  delay(timer_bomba);

  //Ejemplo de proceso de riego
  for (i; i < 3; i++) {
    Serial.print("paso ");
    Serial.println(i);
    //medicion de la humedad del suelo
    pagRiegoInicial();
    //Inicio riego
    pagRiego1();
    delay(timer_bomba);
  }
}
// URI riego
void pagRiegoInicial()
{
  int val=lecturaHumedadSuelo();
  Serial.print("Valor sensor: ");
  Serial.println(val);
}
// URI riego 1
void pagRiego1()
{
  Serial.println("Activacion riego del rele 1");
  activacionRele(RELE_1);
} 
