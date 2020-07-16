#define PONTENCIOMETRO A0
#define LED_1_PIN 9
#define LED_2_PIN 10
#define LED_3_PIN 11
#define LED_4_PIN 12
#define BOTON 7

#define ARRAY_SIZE 4

int pinLedArray[ARRAY_SIZE] = { LED_1_PIN, LED_2_PIN, LED_3_PIN, LED_4_PIN };

unsigned long previusTimer=millis();
int rangoTimer=1000;
int estadoLed=LOW;
int estadoLedBoton=LOW;


void inicializarLeds() {
  //Inicializamos los leds
  for (int i = 0; i < ARRAY_SIZE; i++)pinMode(pinLedArray[i], OUTPUT);

  //Apagamos todos los leds
  for (int i=0;i<ARRAY_SIZE;i++) digitalWrite(pinLedArray[i],LOW);

  //Inicializamos el boton
  pinMode(BOTON,INPUT);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Practica con todo lo aprendido");

  //Inicializaciones
  inicializarLeds();
}

void loop() {
  // put your main code here, to run repeatedly:

  //LED 1: controlado por timer cada segundo
  unsigned long currentTimer=millis();
  if (currentTimer-previusTimer > rangoTimer){
     previusTimer=currentTimer;
     if (estadoLed==LOW) estadoLed=HIGH;
     else estadoLed=LOW;
     
     digitalWrite(LED_1_PIN,estadoLed);
  }
  
  //LED 2: controlado por la entrada de datos
  if (Serial.available()) {
    int userInput = Serial.parseInt();
    if (userInput > 0 && userInput < 256) analogWrite(LED_2_PIN, userInput);
  }
  //LED 3: controlado por el boto
  int valorBoton=digitalRead(BOTON);
  if (valorBoton == LOW){
    if (estadoLedBoton==LOW) estadoLedBoton=HIGH;
    else estadoLedBoton=LOW;
  }
  digitalWrite(LED_3_PIN,estadoLedBoton);
  //LED 4: controlado por el potenciometro
  int valorPotenciometro=analogRead(PONTENCIOMETRO);
  if (valorPotenciometro>512)  digitalWrite(LED_4_PIN,HIGH);
  else  digitalWrite(LED_4_PIN,LOW);
  //Escribir valor del potenciometro casa 2 segundos


  //esperamos un poco
  delay(1000);
}
