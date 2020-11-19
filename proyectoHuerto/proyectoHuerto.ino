//Libraries
#include <dht.h>
dht DHT;
//Constants
#define DHT22_PIN 2       // Sensor DHT 22 
#define YL69_PIN A0       // Sensor YL-69
#define LED_R_PIN 8       // Led roja (sin agua)
#define LUZ_PIN A1        // Sensor  de luz
#define RELE1_PIN 6       // Valor rele 1
#define RELE2_PIN 5       // Valor rele 2

//Calculo del nivel de luz
const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 1;       //Resistencia calibracion en KΩ

//Variables
int minimo_humedad = 200; // Minimo valor de humedad para el riego 
int timer_loop = 20000;   // Delay 2 sec.
int timer_bomba = 7000; // Delay 20 sec.

void setup()
{
    //Inicializacion de resto de componentes
    pinMode(YL69_PIN, INPUT);
    pinMode(LED_R_PIN, OUTPUT);
    pinMode(RELE1_PIN, OUTPUT);
    //pinMode(RELE2_PIN, OUTPUT);
    //Inicializacion logs
    Serial.begin(9600);
}

void loop()
{
  //Mostramos los parametros del ambiente
  imprimeParametros();

  //Comprobamos la maceta 1
  regarPlantaUno();

  //Esperamos la siguientes medidas
  delay(timer_loop);
}
//PARAMETROS AMBIENTE
void imprimeParametros()
{
  Serial.print("Parametros ambiente[");
  //inicializacion del sensor DHT22
  int chk = DHT.read22(DHT22_PIN);    
  //Lectura humedad ambiente
  float hum= DHT.humidity;
  Serial.print("Humedad: ");
  Serial.print(hum);
  //Lectura temperatura ambiente
  float temp= DHT.temperature;
  Serial.print(" -- Temperatura: ");
  Serial.print(temp);
  //Lectura luminosidad
  int valorLDR = analogRead(LUZ_PIN); 
  //Calculamos el valor de la luz
  int ilum = ((long)(1024-valorLDR)*A*10)/((long)B*Rc*valorLDR);  //usar si LDR entre GND y A0 
  Serial.print(" -- Luminosidad: ");
  Serial.print(ilum);
  Serial.println("]");
}
void esperaHumedadReal()
{
  
}
//MACETA 1
void regarPlantaUno()
{
    //Lectura valor humedad de la tierra
    int humedadPlanta1 = analogRead(YL69_PIN);
    Serial.print("Planta 1[ ");
    Serial.print("Humedad:");
    Serial.print(humedadPlanta1);
    //Calculamos si es necesario el riego
    if (humedadPlanta1 < minimo_humedad){
      Serial.println(" -- Inicio riego]");
      //Poner bombas de agua
      digitalWrite(RELE1_PIN, LOW);
      //
      delay(timer_bomba);
      //La paramos
      digitalWrite(RELE1_PIN, HIGH);
    }
}
