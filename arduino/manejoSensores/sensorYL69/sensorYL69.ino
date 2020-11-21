#define PIN_SENSOR A0

int thresholdValue = 800; // valor de ajuste del umbral, para la sensibilidad del sensor

void setup(){
  pinMode(PIN_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // lectura de la entrada analoga pin en A0:
  int sensorValue = analogRead(PIN_SENSOR);
  Serial.print(sensorValue);Serial.print(" - ");
  if(sensorValue >= thresholdValue){
    Serial.println(" Suelo seco, necesita regarse");
  }
  delay(500);
}
