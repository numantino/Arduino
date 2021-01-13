#include "controlSensoresDHT22.hpp"
#include "clienteIFTTT.hpp"

void setup()
{
    Serial.begin(115200);
    delay(10);
    //Inicializacion del componente, dependiendo de la clase incluida con anterioridad
    inicializacion();
}
void loop()
{
  //Lectura sensor DHT22
  TempAndHumidity lastValues =lecturaDatosDHT22();
  //Envio de los datos
  envioDatosDHT22(String(lastValues.temperature,0),String(lastValues.humidity,0));
  delay(20000);
}
