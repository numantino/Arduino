//Libraries
#include <DHTesp.h>
//Constants
//#define SENSOR_DHT22 2     // DHT 22  (AM2302) - what pin we're connected to
#define SENSOR_DHT22 D1
//Calse que realiza las comprobaciones de control
DHTesp dht;

void setup()
{
    Serial.begin(9600);
    Serial.println("Inicio");
}

void loop()
{
    dht.setup(SENSOR_DHT22, DHTesp::DHT22);
    TempAndHumidity lastValues = dht.getTempAndHumidity();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(String(lastValues.humidity,0));
    Serial.print(" %, Temp: ");
    Serial.print(String(lastValues.temperature,0));
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
}
