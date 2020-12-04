/*
 * Clase encargada de presentar valores del ambiente
 * 
 */
//Objeto para el control del sensor DHT22
DHTesp dht;

//Valores para el calculo de la luminosidad
const long A = 1000;     //Resistencia en oscuridad en KΩ (depende de la resistencia usada)
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ

/*
 * Recuperar los datos del sensor DHT22
 * Humedad --> String(lastValues.humidity,0),
 * Temperatura --> String(lastValues.temperature,0)
 */
TempAndHumidity lecturaDatosDHT()
{
  dht.setup(SENSOR_DHT22, DHTesp::DHT22);
  TempAndHumidity lastValues = dht.getTempAndHumidity();
  return lastValues;
}
/*
 * Recupera la intensidad de luz
 */
int lecturaDatosLuz()
{
   int V = analogRead(SENSOR_LDR);     
   int ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   return ilum;
}
/*
 * Interfaz web
 */
String interfazInformacion(float hum, float temp, int luz)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                          "<meta charset='UTF-8'>"
                          "<html>"
                          "<head>"
                          "<title>Control riego automatico</title>"
                          "</head>"
                          "<body>"
                          "<h1>Datos ambiente</h1>";
     HtmlRespuesta +="<p> </p>";
    //Creamos la tabla de datos
    HtmlRespuesta +="<table style=\"width:19%\" border=1>";
    HtmlRespuesta +="<tr>"
                    "<td>Humedad Ambiente</td>"
                    "<td>  ";
    HtmlRespuesta +=String(hum,0);
    HtmlRespuesta +=" %</td>";
    HtmlRespuesta +="</tr>"
                    "<tr>"
                    "<td>Temperatura Ambiente</td>"
                    "<td>  ";
    HtmlRespuesta +=String(temp,0);
    HtmlRespuesta +=" ºC</td>"
                    "</tr>";
    HtmlRespuesta +="<tr>"
                    "<td>Intensidad de la luz</td>"
                    "<td>  "
                    "</tr>"
                    "</table>";
    HtmlRespuesta +="<p></p>"
                    "<p></p>";
    //Creacion de los botones
    HtmlRespuesta +="<button type=\"button\" onClick=location.href='/riego' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'>INICIAR RIEGO</button>"; 
    HtmlRespuesta +="<p></p>";
	//recalcular los valores
	HtmlRespuesta +="<a href='/'>Recalcular</a>"
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}
