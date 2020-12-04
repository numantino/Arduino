/*
 * Clase encargada del control del riego automatico
 * 
 */
//Valores control del sensor de humedad de la tierra
int minimo_humedad = 200; // Minimo valor de humedad para el riego 
int timer_bomba = 7000;   // Delay 20 sec.

/*
 * Recuperamos informacion de la humedad del suelo
 */
int lecturaHumedadSuelo()
{
 int humedadSuelo = analogRead(SENSOR_YL69);
 return humedadSuelo;
}
/**
 * activamos el rele para que pueda dar agua durante un tiempo
 */
void activacionRele(int posicion)
{
  Serial.println(" -- Inicio del riego --");
  //Poner bombas de agua
  digitalWrite(posicion, LOW);
  //esperamos un tiempo
  delay(timer_bomba);
  //Paramos bomba de agua
  digitalWrite(posicion, HIGH);  
}
/*
 * Calculamos si es necesario realizar el riego, dependiendo de la humedad del suelo
 */
bool activarRiegoAutomatico()
{
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
    HtmlRespuesta +=String(humedad,0);
    HtmlRespuesta +=" %</p>";
    HtmlRespuesta +="<p></p>";
    //Creacion de los botones
    HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego1' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>PLANTA 1</button>"; 
    HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego2' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>PLANTA 2</button>"; 
	HtmlRespuesta +="<p></p>";
	//volver a la pagina inicial
	HtmlRespuesta +="<a href='/'>Pagina inicial</a>"
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}
