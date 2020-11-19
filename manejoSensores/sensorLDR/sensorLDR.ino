#define PIN_LDR A0    //Seleccionamos el pin analógico A0 como input del sensor LDR. 

//Constantes
const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ

void setup() { 
  Serial.begin(9600); //Inicializamos monitor serie para visualizar los valores de LDR. 
}

void loop() { 
  lecturaNormal();
  lecturaNivelLuz();
  
  delay(1000);                          // esperar un segundo  
}
void lecturaNivelLuz()
{
   int V = analogRead(PIN_LDR);     
   int ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   Serial.print("Lectura nivel luz: ");
   Serial.println(ilum);            
}
void lecturaNormal()
{
  int valorLDR = analogRead(PIN_LDR);   //Leemos el valor del pinLDR y lo guardamos en la variable creada.
  Serial.print("Lectura luz: ");
  Serial.println(valorLDR);             //Imprimimos dicho valor, comprendido entre 0 y 1023. 
}
