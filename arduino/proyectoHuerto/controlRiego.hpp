/*
 * Clase encargada de: 
 *          control de los sonseres de humedad 
 *          control de las bombas de agua
 * 
 */
//Valores control del sensor de humedad de la tierra
int minimo_humedad;
int timer_bomba;

/**
 * Funciones para el control del sensor de humedad (YL69)
 */
void iniYL69(int id, int m)
{
  pinMode(id, INPUT);
  //Inicializamos valor minimo de humedad
  minimo_humedad = m;  
}
int lecturaHumedadSuelo()
{
 int humedadSuelo = analogRead(SENSOR_YL69);
 return humedadSuelo;
}
bool sueloSeco(int h_suelo)
{
  if (h_suelo < minimo_humedad) return true;
  else return false;
}
/**
 * Funciones para el control del rele, en la bomba de agua
 */
void iniRele(int id, int t)
{
  pinMode(id, OUTPUT);
  //Empezamos con la bomba de agua apagada
  digitalWrite(id, HIGH); 
  //Inicializamos el timer de la bomba
  timer_bomba = t;
}
void activacionRele(int id)
{
  Serial.println(" -- Inicio del riego --");
  //Poner bombas de agua
  digitalWrite(id, LOW);
  //esperamos un tiempo
  delay(timer_bomba);
  //Paramos bomba de agua
  digitalWrite(id, HIGH);  
  Serial.println(" -- Fin del riego --");
}
void apagarBomba(int id)
{
  digitalWrite(id, HIGH); 
}
/*
 * Interfaz web
 */
String interfazRiego(int humedad)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                          "<meta charset='UTF-8'>"
                          "<html>"
                          "<head>"
                          "<title>Control riego automatico</title>"
                          "</head>"
                          "<body>"
                          "<h1>Riego automatico</h1>";
    HtmlRespuesta +="<p></p>";
    HtmlRespuesta +="<p>Valor de la humedad del suelo ";
    HtmlRespuesta +=String(humedad);
    HtmlRespuesta +=" %</p>";
    HtmlRespuesta +="<p></p>";
    //Creacion de los botones
    HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego1' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>PLANTA 1</button>"; 
    HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego2' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>PLANTA 2</button>"; 
	  HtmlRespuesta +="<p></p>";
	  //volver a la pagina inicial
	  HtmlRespuesta +="<a href='/'>Pagina inicial</a>";
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}
