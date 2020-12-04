//Configuracion de la red wifi
const char* ssid     = "numantino";
const char* password = "123456789";
const char* hostname = "ESP8266_1";

//http://192.168.1.2
IPAddress ip(192, 168, 1, 2);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

//configuracion servidor
const int PUERTO = 80;    
