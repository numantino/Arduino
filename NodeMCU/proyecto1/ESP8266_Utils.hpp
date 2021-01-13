/*
 * Clase encargada de la conexion wifi
 * Usar siempre una conexion 2g
 * 
 * Version= 1.1
 */
#include <ESP8266WiFi.h> 

//Datos WIFI casa
#define SSID_CASA "MIWIFI_2G_MNuK"
#define PWD_CASA "aQ9EkE3e"
//Datos WIFI red propia
#define SSID_PROPIA "numantino"
#define PWD_CASA "123456789"

//Datos creacion red http://192.168.1.2
IPAddress ip(192, 168, 1, 2);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

//Conectar con una red wifi pasandole los parametros
void conexionWifi(char* ssid,char* password)
{
  WiFi.begin(ssid, password);
  Serial.println("--> Esperando WiFi... ");
  Serial.print("-> Conectado a WIFI : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("--> WiFi conectada");
}
//Conectar con una red wifi pasandole los parametros
void conexionWifi2(char* ssid,char* password)
{
  Serial.println("--> Esperando creacion WiFi... "); 
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(ip, gateway, subnet);
  delay(100);
  Serial.print("-> Conectado a WIFI : ");
  Serial.println(ssid);
  Serial.println("-> Conectar a http://192.168.1.2");
  Serial.println("--> WiFi conectada");
}
//Crear una conexion de red
void conexionWifiMode(char* ssid,char* password,WiFiMode modo =WIFI_AP,  bool useStaticIP = false)
{ 
   Serial.println("--> Esperando WiFi... ");
   Serial.print("-> Modo: ");
   Serial.println(modo);
   WiFi.mode(modo);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(100);
   }
   if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

   Serial.print("->Iniciado AP:\t");
   Serial.println(ssid);
   Serial.println("--> WiFi conectada");
}
