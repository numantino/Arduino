#include <EEPROM.h>

#define LED_PIN_R 12
#define LED_PIN_A 11
#define LED_PIN_V 10
#define LED_PIN_B 9

#define MAX_ARRAY 4
#define VAL_LED_INICIAL 0

int arrayLed[MAX_ARRAY] = {LED_PIN_R,LED_PIN_A,LED_PIN_V,LED_PIN_B};

void apagarTodosLed(){
  //Apagamos todos los leds
  for (int i=0;i<MAX_ARRAY;i++) digitalWrite(arrayLed[i],LOW);
}

void encenderLed(int pos_led){
  //Encendemos el led indicado
   if (pos_led>=0 && pos_led<MAX_ARRAY){
    digitalWrite(arrayLed[pos_led],HIGH);
   }
}

void inicializacion(){
  Serial.println("Inicializacion");
  //Inicializamos puertos
  for (int i=0;i<MAX_ARRAY;i++) pinMode(arrayLed[i],OUTPUT);

  //Apagamos la luces
  apagarTodosLed();

  //Recuperamos informacion de memoria
  int va_inicial_led=EEPROM.read(VAL_LED_INICIAL);
  encenderLed(va_inicial_led);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ejercicio comunicacion");

  //Inicializacion
  inicializacion();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0){
    int pos_led=Serial.parseInt();
    //apagamos todos primero
    
    //encendemos el que nos indican
    if (pos_led>0 && pos_led<=MAX_ARRAY){
      apagarTodosLed();
      encenderLed(pos_led-1);
      //Almacenamos el valor en memoria
      EEPROM.write(VAL_LED_INICIAL,pos_led-1);
    }
  }
}
