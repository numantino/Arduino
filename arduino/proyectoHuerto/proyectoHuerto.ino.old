//Libraries
#include <dht.h>

//Motor y sensores
#define RELE_PIN_1 6       // Valor rele 1
//#define RELE_PIN_2 5       // Valor rele 2
#define YL69_PIN_1 A0     // Sensor YL-69 maceta 1
//#define YL69_PIN_2 A1     // Sensor YL-69 maceta 2

//Sensores externos
#define S_LUZ A2         // Sensor  de luz
#define DHT22_PIN 2       // Sensor DHT 22 


//Sensor DHT22
dht DHT;

//Intensidad Sensor LUZ
const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 1;       //Resistencia calibracion en KΩ

//Sensor YL69
int minimo_humedad = 200; // Minimo valor de humedad para el riego 
int timer_loop = 20000;   // Delay 2 sec.
int timer_bomba = 7000; // Delay 20 sec.

void setup()
{
    //Inicializacion de resto de componentes
    pinMode(YL69_PIN_1, INPUT);
    pinMode(RELE_PIN_1, OUTPUT);
    //pinMode(RELE_PIN_2, OUTPUT);
    //Inicializacion logs
    Serial.begin(9600);
}

void loop()
{
  //Mostramos los parametros del ambiente
  lecturaDatos();

  //Comprobamos la maceta 1
  if (necesitaRiego(YL69_PIN_1)) regar(RELE_PIN_1);
  //Comprobamos la maceta 2
  //if (necesitaRiego(YL69_PIN_2)) regar(RELE_PIN_2);
  
  //Esperamos la siguientes medidas
  delay(timer_loop);
}
//Lectura humedad ambiente
float humedadAmbiente()
{
  int chk = DHT.read22(DHT22_PIN); 
  float hum= DHT.humidity;
  return hum;
}
//Lectura temperatura ambiente
float temperaturadAmbiente()
{
  int chk = DHT.read22(DHT22_PIN); 
  float temp= DHT.temperature;
  return temp;
}
//Lectura luminosidad
int lecturaLuz()
{
  int valorLDR = analogRead(S_LUZ); 
  //Calculamos el valor de la luz dependiendo de las resistencias
  int ilum = ((long)(1024-valorLDR)*A*10)/((long)B*Rc*valorLDR);  //usar si LDR entre GND y A0 
  return ilum;
}
void lecturaDatos()
{
  Serial.print("Datos ambiente[ ");
  float h=humedadAmbiente();
  Serial.print("Humedad: ");
  Serial.print(h);
  float t=temperaturadAmbiente();
  Serial.print(" -- Temperatura: ");
  Serial.print(t);
  int l=lecturaLuz();
  Serial.print(" -- Int. luz: ");
  Serial.print(l);
  Serial.println(" ]");
}
bool necesitaRiego(int id){
  int humedadPlanta1 = analogRead(id);
  Serial.print("Humedad planta 1:");
  Serial.println(humedadPlanta1);
  if (humedadPlanta1 < minimo_humedad) return true;
  else return false;
}
bool tenemosAgua(){
  return true;
}
void regar(int id)
{
    //Comprobamos el nivel del agua
    if (tenemosAgua()){
      Serial.println(" -- Inicio del riego --");
      //Poner bombas de agua
      digitalWrite(id, LOW);
      //esperamos un tiempo
      delay(timer_bomba);
      //Paramos bomba de agua
      digitalWrite(id, HIGH);  
    }
    else Serial.println(" -- No tenemos agua para el riego --");
}
