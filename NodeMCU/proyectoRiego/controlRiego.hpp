/*
 * Clase encargada de: 
 *          control de los sonseres de humedad 
 *          control de las bombas de agua
 * 
 */

//VALORES RELE (control bomba de agua)
#define RELE_1 D1      
#define RELE_2 D2    
#define SENSOR_YL69 A0    


//Valores control del sensor de humedad de la tierra
int minimo_humedad;
int timer_bomba;

/**
 * Funciones para el control del sensor de humedad (YL69)
 */
void iniYL69(int id, int m)
{
  pinMode(id, INPUT);
  minimo_humedad = m;  
}
void setMinimoHumedad(int m)
{
   minimo_humedad = m;
}
int lecturaHumedadSuelo(int id)
{
 int humedadSuelo = analogRead(id);
 return humedadSuelo;
}
bool sueloSeco(int id)
{
  //Lectura de los valores del suelo
  int h_suelo = lecturaHumedadSuelo(id);
  //Calculamos si necesitamos regar
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
void setTimerBomba(int t)
{
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
String interfazInicial(int humedad)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                          "<meta charset='UTF-8'>"
                          "<html>"
                          "<head>"
                          "<title>Control riego automatico</title>"
                          "</head>"
                          "<body>"
                          "<h1>Proceso de riego</h1>";
    //Planta 1
    HtmlRespuesta +="<p>Humedad del suelo de ";
    HtmlRespuesta +=String(humedad);
    HtmlRespuesta +=" %</p>";
    HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego1' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>PLANTA 1</button>"; 
    HtmlRespuesta +="<p></p>";
    //Planta 2
    //HtmlRespuesta +="<p>Humedad del suelo de ";
    //HtmlRespuesta +=String(humedad);
    //HtmlRespuesta +=" %</p>";
    //HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego2' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>PLANTA 2</button>"; 
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}
String interfazRiego(int id)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                          "<meta charset='UTF-8'>"
                          "<html>"
                          "<head>"
                          "<title>Control riego automatico</title>"
                          "</head>"
                          "<body>"
                          "<h1>Iniciamos el riego de la bomba ";
    HtmlRespuesta +=String(id);
    HtmlRespuesta +=" </h1>";
    //Creacion de los botones
    HtmlRespuesta +="<p></p>";
    HtmlRespuesta +="<a href='/'>Pagina inicial</a>";
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}
