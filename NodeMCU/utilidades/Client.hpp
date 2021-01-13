/*
 * CONEXION MEDIANTE HTTP
 * 
 * Usamos la plataforma api.thingspeak.com
 * 
 * Version= 1.1
 */
#include "ESP8266_Utils.hpp"
//Datos conexion entorno
#define SERVER_THINGSPEAK "api.thingspeak.com"

//Variable necesarias para la conexion
char* server;
String apiKey; 
int port;
//Objeto que gestiona las conexiones cel cliente
WiFiClient client;
//Inicializacion de los componentes
void inicializacion()
{
  //Conexion wifi de casa
  conexionWifi(SSID_CASA,PWD_CASA);
  
  //Configuramos parametros en relacion a la 
  server=SERVER_THINGSPEAK;
  apiKey="NNQ6E2KC25K0G2YE";
  port=80;
}
/*
 * Envio de los datos del sensor DHT22
 */
void envioDatosDHT22(String t, String h)
{
  // Hacemos la petición mediante SSL
  if (client.connect(server,port)) { 
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += t;
    postStr +="&field2=";
    postStr += h;
    postStr += "\r\n\r\n";
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
  }
  
  // Esperamos hasta que se hayan enviado todos los datos
  client.flush();
  // Desconectamos del cliente
  client.stop();
}
