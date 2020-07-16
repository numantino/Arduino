#define LED_PIN_R 12
#define LED_PIN_A 11
#define LED_PIN_V 10
#define LED_PIN_B 9
#define BOTON_1 5

#define MAX_ARRAY 4

int arrayLed[MAX_ARRAY] = {LED_PIN_R,LED_PIN_A,LED_PIN_V,LED_PIN_B};
bool arbolEncendido=true;
bool botonPulsado=false;

void apagarTodosLed(){
  //Apagamos todos los leds
  for (int i=0;i<MAX_ARRAY;i++) digitalWrite(arrayLed[i],LOW);
}

void iniciarLoop(){
  for (int i=0;i<MAX_ARRAY;i++){
    apagarTodosLed();
    digitalWrite(arrayLed[i], HIGH);
    delay(500);
  }
}

bool botonPulsadoFun(){
  int valorBoton=digitalRead(BOTON_1);
  if (valorBoton == HIGH) return true;
  else return false;
}

void setup() {
  //Inicializacion del boton
  pinMode(BOTON_1,INPUT);
  //Inicializacion de luces
  for (int i=0;i<MAX_ARRAY;i++) pinMode(arrayLed[i],OUTPUT);
  //encendido de luces inicial
  iniciarLoop();
}

void loop() {
  delay(500);
  //Obtenemos valor del boton
  botonPulsado=botonPulsadoFun();
  if (arbolEncendido && botonPulsado) apagarTodosLed();
  else if (!arbolEncendido && botonPulsado) iniciarLoop();
}
