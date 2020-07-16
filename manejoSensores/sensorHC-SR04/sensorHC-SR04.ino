#include <NewPing.h>
 
const int UltrasonicPin = 5;
const int MaxDistance = 200;
 
NewPing sonar(UltrasonicPin, UltrasonicPin, MaxDistance);
 
void setup() {
  Serial.begin(9600);
  Serial.println("Inicio Sensor ultrasonidos HC-SR04");
}
 
void loop() {
  delay(50);                      // esperar 50ms entre pings (29ms como minimo)
  Serial.print(sonar.ping_cm()); // obtener el valor en cm (0 = fuera de rango)
  Serial.println("cm");
}
