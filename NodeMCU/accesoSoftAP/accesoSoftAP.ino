#include <ESP8266WiFi.h>   
#include <ESP8266WebServer.h> 
#include <DHTesp.h> 
#include "config.h"
#include "ESP8266_conf.h"
#include "ESP8266_Utils.hpp"
#include "Server.hpp"


void setup() {
  Serial.begin(9600);
  //Iniciamos acceso wifi
  ConnectWiFi();
  delay(100);
  //Inicializamos servidor
  InitServer();
}

void loop() {
  server.handleClient();
}
