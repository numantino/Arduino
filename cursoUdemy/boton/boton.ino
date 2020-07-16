#define BOTON 7

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(BOTON,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valorBoton=digitalRead(BOTON);
  if (valorBoton == LOW){
    Serial.println("Boton presionado");
  }
  else{
    Serial.println("--");
  }
  delay(500);
}
