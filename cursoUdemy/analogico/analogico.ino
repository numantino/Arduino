#define PONTENCIOMETRO A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ejercicio analogico");
}

void loop() {
  // put your main code here, to run repeatedly:
  int value= analogRead(PONTENCIOMETRO);
  Serial.println(value);
  delay(100);
}
