//Ejemplo de manejo de leds
#define LED 7

void setup() {
  pinMode(LED, OUTPUT);
  
}

void loop() {
  digitalWrite(LED , HIGH);   // poner el Pin en HIGH
  delay(1000);                   // esperar un segundo
  digitalWrite(LED , LOW);    // poner el Pin en LOW
  delay(1000);                   // esperar un segundo
}
