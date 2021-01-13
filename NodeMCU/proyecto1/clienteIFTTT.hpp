/*
 * CONEXION MEDIANTE IFTTT
 * 
 * Usamos la plataforma https://ifttt.com
 * 
 * Version= 1.2
 */
#include "ESP8266_Utils.hpp"

//Datos conexion entorno
#define SERVER_IFTTT "maker.ifttt.com"

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
  server=SERVER_IFTTT;
  apiKey="";
  port=443;
}
//Generamos los datos que enviaremos a Twitter
String generarDatosTwitter(String t, String h)
{
    String EVENTO= "nombre_tu_evento"; //Esto es el nombre del evento

    //Generamos el mensaje
    String toSend = "GET /trigger/";
    toSend += EVENTO;
    toSend += "/with/key/";
    toSend += apiKey;
    toSend += "?value1=";
    toSend += t;
    toSend += "&value2=";
    toSend += h;
    toSend += " HTTP/1.1\r\n";
    toSend += "Host: ";
    toSend += server;
    toSend += "\r\n";
    toSend += "Connection: close\r\n\r\n";
    
    return toSend;
}
/*
 * Envio de los datos del sensor DHT22
 */
void envioDatosDHT22(String t, String h)
{
  // Enviamos peticion HTTP
  if (client.connect(server, port)) client.print(generarDatosTwitter(t,h));
  // Esperamos hasta que se hayan enviado todos los datos
  client.flush();
  // Desconectamos del cliente
  client.stop();
}
