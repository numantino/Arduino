//Objeto para el control del  servidor
ESP8266WebServer server(80);

// Funcion que se ejecutara en URI desconocida
void pagNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
// URI inicial
void pagInformacion()
{
  //Lectura sensor DHT
  TempAndHumidity lastValues =lecturaDatosDHT();
  //Lectura sensor LUZ
  int datoLuz=lecturaDatosLuz();
  server.send(200, "text/html", interfazInformacion(lastValues.humidity,lastValues.temperature,datoLuz));
}
// URI riego
void pagRiegoInicial()
{
  server.send(200, "text/html", interfazRiego(lecturaHumedadSuelo()));
}
// URI riego 1
void pagRiego1()
{
  Serial.println("Activacion riego del rele 1");
  activacionRele(RELE_1);
  delay(100);
  server.send(200, "text/html", interfazRiego(lecturaHumedadSuelo()));
} 
// URI riego 2
void pagRiego2()
{
  Serial.println("Activacion riego del rele 2");
  activacionRele(RELE_2);
  delay(100);
  server.send(200, "text/html", interfazRiego(lecturaHumedadSuelo()));
}
void inicioServidor()
{
   // Rutas
   server.on("/", pagInformacion);
   server.on("/riego", pagRiegoInicial);
   server.on("/riego1", pagRiego1);
   server.on("/riego2", pagRiego2);
   server.onNotFound(pagNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP servidor activo");
}
