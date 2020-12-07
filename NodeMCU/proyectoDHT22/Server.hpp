//Objeto para el control del  servidor
ESP8266WebServer server(80);

// Funcion que se ejecutara en URI desconocida
void pagNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
// URI mustra informacion DHT22
void pagInformacionDHT22()
{
  //Lectura sensor DHT
  TempAndHumidity lastValues =lecturaDatosDHT22();
  server.send(200, "text/html", interfazInformacionDHT22(lastValues.humidity,lastValues.temperature));
}
void inicioServidor()
{
   // Rutas
   server.on("/", pagInformacionDHT22);
   server.onNotFound(pagNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP servidor activo");
}
