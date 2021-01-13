/*
 * Clase encargada de generar un servidor en el dispositivo
 * 
 * Version= 1.2
 */
#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 
#include "controlSensoresDHT22.hpp"
#include "ESP8266_Utils.hpp"

//Objeto para el control del  servidor
ESP8266WebServer server(80);

/*
 * Interfaz web
 */
String interfazInformacionDHT22(float hum, float temp)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                          "<meta charset='UTF-8'>"
                          "<html>"
                          "<head>"
                          "<title>Control sensor DHT22</title>"
                          "</head>"
                          "<body>"
                          "<h1>Datos ambiente</h1>";
     HtmlRespuesta +="<p> </p>";
    //Creamos la tabla de datos
    HtmlRespuesta +="<table style=\"width:20%\" border=1>";
    HtmlRespuesta +="<tr>"
                    "<td>Humedad </td>"
                    "<td>";
    HtmlRespuesta +=String(hum);
    HtmlRespuesta +=" %</td>";
    HtmlRespuesta +="</tr>"
                    "<tr>"
                    "<td>Temperatura</td>"
                    "<td>";
    HtmlRespuesta +=String(temp);
    HtmlRespuesta +=" ºC</td>"
                    "</tr>";            
    HtmlRespuesta +="</table>";
    HtmlRespuesta +="<p></p>";
    //recalcular los valores
    HtmlRespuesta +="<a href='/'>Recalcular</a>";
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}

// Funcion que se ejecutara en URI desconocida
void pagNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
// URI mustra informacion DHT22
void pagDatosDHT22()
{
  TempAndHumidity lastValues =lecturaDatosDHT22();
  server.send(200, "text/html", interfazInformacionDHT22(lastValues.humidity,lastValues.temperature));
}
// Con este proceso se inicia el servidor con los datos de la wifi pasados por parametro
void inicializacion()
{
  //Iniciamos acceso wifi
  conexionWifi2(SSID_PROPIA,PWD_CASA);
  delay(100);
    
   // Rutas
   server.on("/", pagDatosDHT22);
   server.onNotFound(pagNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP servidor activo");
}
