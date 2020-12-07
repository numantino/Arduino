//Objeto para el control del  servidor
ESP8266WebServer server(80);

// Funcion que se ejecutara en URI desconocida
void pagNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
// URI riego
void pagRiegoInicial()
{
  int val=lecturaHumedadSuelo(SENSOR_YL69);
  server.send(200, "text/html", interfazInicial(val));
}
// URI riego 1
void pagRiego1()
{
  Serial.println("Activacion riego del rele 1");
  server.send(200, "text/html", interfazRiego(1));
  activacionRele(RELE_1);
} 
// URI riego 2
void pagRiego2()
{
  Serial.println("Activacion riego del rele 2");
  server.send(200, "text/html", interfazRiego(2));
  activacionRele(RELE_2);
}
void inicioServidor()
{
   // Rutas
   server.on("/", pagRiegoInicial);
   server.on("/riego1", pagRiego1);
   server.on("/riego2", pagRiego2);
   server.onNotFound(pagNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP servidor activo");
}
