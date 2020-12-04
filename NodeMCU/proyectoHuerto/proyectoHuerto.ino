#include <ESP8266WiFi.h>   
#include <ESP8266WebServer.h> 
#include <DHTesp.h> 
#include "conf.h"
#include "controlRiego.hpp"
#include "controlSensores.hpp"
#include "ESP8266_Utils.hpp"
#include "Server.hpp"


void setup()
{
    Serial.begin(9600);
    //Iniciamos acceso wifi
    ConnectWiFi();
    delay(100);
    //Iniciamos los sensores
    pinMode(SENSOR_YL69, INPUT);
    pinMode(RELE_1, OUTPUT);
    //Inicializamos servidor
    inicioServidor();
}

void loop()
{
  server.handleClient();
}
