//CONSTANTES
const int T_DELAY=100;   
//VALORES SENSOR DHT22 (temperatura y humedad ambiente)
#define SENSOR_DHT22 D1  
//VALORES SENSOR LDR (luminosidad)
#define SENSOR_LDR D2 
//VALORES RELE (control bomba de agua)
#define RELE_1 8  			//Rele 1    
#define RELE_2 9   		//Rele 2
const int T_BOMBA=7000;   // Delay 20 sec.
//VALORES SENSOR YL69 (humedad tierra)
#define SENSOR_YL69 A0		
const int MIN_HUMEDAD = 200; // Minimo valor de humedad para el riego 
