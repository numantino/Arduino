//Objeto para el control del  servidor
ESP8266WebServer server(80);

// Funcion que se ejecutara en URI desconocida
void pagNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
// URI mustra informacion DHT22
void pagInicio()
{
  server.send(200, "text/html", <INTERFAZ QUE SE QUIERE MOSTRAR>);
}
void inicioServidor()
{
   // Rutas
   server.on("/", pagInicio);
   //Incluir resto de paginas
   server.onNotFound(pagNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP servidor activo");
}
