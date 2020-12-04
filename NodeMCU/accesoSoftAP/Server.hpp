//Objeto para el control del  servidor
ESP8266WebServer server(80);
//Objeto para el control del sensor DHT22
DHTesp dht;

String obtenerInterfaz(String h, String t, String l)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                         "<html lang='en'>"
                         "<head>"
                         "<meta charset='UTF-8'>"
                         "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
                         "<title>Datos Ambiente</title>"
                         "</head>"
                         "<body>";
  HtmlRespuesta += "<h1>DATOS AMBIENTE</h1>";
  HtmlRespuesta += "<p>La temperatura actual es de  <strong>";
  HtmlRespuesta += t;
  HtmlRespuesta += " ºC</strong></p>";
  HtmlRespuesta += "<p></p>";
  HtmlRespuesta += "<p>La humedad actual es de  <strong>";
  HtmlRespuesta += h;
  HtmlRespuesta += " %</strong></p>";
  HtmlRespuesta += "<p>La cantidad de luz es de  <strong>";
  HtmlRespuesta += l;
  HtmlRespuesta += " </strong></p>";
  HtmlRespuesta += "</body>"
                   "</html>";
  return HtmlRespuesta;
}

// Funcion que se ejecutara en URI desconocida
void handleNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
TempAndHumidity lecturaDatosDHT()
{
  dht.setup(SENSOR_DHT22, DHTesp::DHT22);
  TempAndHumidity lastValues = dht.getTempAndHumidity();
  return lastValues;
}
int lecturaDatosLuz()
{
   int V = analogRead(SENSOR_LDR);     
   int ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   return ilum;
}
//Datos de humedad y 
void handleLeerDatos(){
  //Lectura sensor 
  TempAndHumidity lastValues =lecturaDatosDHT();
  int datoLuz=lecturaDatosLuz();
  server.send(200, "text/html", obtenerInterfaz(String(lastValues.humidity,0),String(lastValues.temperature,0),String(datoLuz)));
}
 
void InitServer()
{
   // Rutas
   server.on("/", handleLeerDatos);
   server.onNotFound(handleNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP server started");
}
