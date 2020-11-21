const int sensorPin = 7;

 
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  Serial.println("Inicio obstaculo");
  pinMode(sensorPin , INPUT);  //definir pin como entrada
}
 
void loop(){
  int value = 0;
  value = digitalRead(sensorPin );  //lectura digital de pin
 
  if (value == HIGH) {
      Serial.println("Detectado obstaculo");
  }
  delay(1000);
}
