/*
 * Clase encargada de controlar el SENSOR DHT22 de temperatura y humedad ambiente
 * 
 */
//VALORES 
#define SENSOR_DHT22 D1    

//Calse que realiza las comprobaciones de control
DHTesp dht;
/*
 * Recuperar los datos del sensor DHT22
 * Humedad --> String(lastValues.humidity,0),
 * Temperatura --> String(lastValues.temperature,0)
 */
TempAndHumidity lecturaDatosDHT22()
{
  dht.setup(SENSOR_DHT22, DHTesp::DHT22);
  TempAndHumidity lastValues = dht.getTempAndHumidity();
  return lastValues;
}
/*
 * Interfaz web
 */
String interfazInformacionDHT22(float hum, float temp)
{
  String HtmlRespuesta = "<!DOCTYPE html>"
                          "<meta charset='UTF-8'>"
                          "<html>"
                          "<head>"
                          "<title>Control sensor DHT22</title>"
                          "</head>"
                          "<body>"
                          "<h1>Datos ambiente</h1>";
     HtmlRespuesta +="<p> </p>";
    //Creamos la tabla de datos
    HtmlRespuesta +="<table style=\"width:20%\" border=1>";
    HtmlRespuesta +="<tr>"
                    "<td>Humedad </td>"
                    "<td>";
    HtmlRespuesta +=String(hum);
    HtmlRespuesta +=" %</td>";
    HtmlRespuesta +="</tr>"
                    "<tr>"
                    "<td>Temperatura</td>"
                    "<td>";
    HtmlRespuesta +=String(temp);
    HtmlRespuesta +=" ºC</td>"
                    "</tr>";            
    HtmlRespuesta +="</table>";
    HtmlRespuesta +="<p></p>";
	  //recalcular los valores
	  HtmlRespuesta +="<a href='/'>Recalcular</a>";
    HtmlRespuesta +="</body>"
                    "</html>";
                    
  return HtmlRespuesta;
}
