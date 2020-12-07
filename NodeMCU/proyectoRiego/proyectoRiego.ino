#include <ESP8266WiFi.h>   
#include <ESP8266WebServer.h> 
#include <DHTesp.h> 
#include "controlRiego.hpp"
#include "ESP8266_Utils.hpp"
#include "Server.hpp"


void setup()
{
    Serial.begin(9600);
    //Iniciamos acceso wifi
    ConnectWiFi();
    delay(100);
    //Inicializacion de los componentes
    iniYL69(SENSOR_YL69, 200); // Minimo valor de humedad para el riego 
    iniRele(RELE_1,7000); //tiempo de espera entre descarga (Delay 20 sec.)
    //Inicializamos servidor
    inicioServidor();
}

void loop()
{
  server.handleClient();
}
