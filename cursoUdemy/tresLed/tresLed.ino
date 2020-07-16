#define LED_PIN_R 12
#define LED_PIN_A 11
#define LED_PIN_V 10
#define LED_PIN_B 9

#define MAX_ARRAY 4

int arrayLed[MAX_ARRAY] = {LED_PIN_R,LED_PIN_A,LED_PIN_V,LED_PIN_B};

void apagarTodosLed(){
  //Apagamos todos los leds
  for (int i=0;i<MAX_ARRAY;i++) digitalWrite(arrayLed[i],LOW);
}

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<MAX_ARRAY;i++) pinMode(arrayLed[i],OUTPUT);

  //Apagamos la luces
  apagarTodosLed();
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=0;i<MAX_ARRAY;i++){
    apagarTodosLed();
    digitalWrite(arrayLed[i], HIGH);
    delay(500);
  }
}
