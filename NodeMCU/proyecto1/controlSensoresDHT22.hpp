/*
 * Clase encargada de controlar el SENSOR DHT22 de temperatura y humedad ambiente
 * 
 * Version= 1.2
 */
#include <DHTesp.h> 

//PIN entrada de datos 
#define SENSOR_DHT22 D1    

//Calse que realiza las comprobaciones de control
DHTesp dht;
/*
 * Recuperar los datos del sensor DHT22
 * Humedad --> String(lastValues.humidity,0),
 * Temperatura --> String(lastValues.temperature,0)
 */
TempAndHumidity lecturaDatosDHT22()
{
  dht.setup(SENSOR_DHT22, DHTesp::DHT22);
  TempAndHumidity lastValues = dht.getTempAndHumidity();
  //Mostramos los datos de lectura
  Serial.print("--> Lectura datos sensor DHT22[t=");
  Serial.print(String(lastValues.temperature,0));
  Serial.print(",h=");
  Serial.print(String(lastValues.humidity,0));
  Serial.println("]");
  return lastValues;
}
