#define RELE_1_PIN 8     // Valor rele 1
#define RELE_2_PIN 7     // Valor rele 2

int incomingByte = 0; // valores de entrada

void setup() {
    pinMode(RELE_1_PIN, OUTPUT);
    //pinMode(RELE_2_PIN, OUTPUT);
    //trazas
    Serial.begin(9600);
    Serial.print("Inicio rele");
    //inicializamos apagado el rele
    rele1(false);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    if (incomingByte == '1') rele1(true);
    else if (incomingByte == '2') rele1(false);
  }
  delay(1000);
}

void rele1(bool activo)
{
  if (activo)
  {
     Serial.println("Activamos rele 1");
     digitalWrite(RELE_1_PIN, LOW);
  }
  else
  {
     Serial.println("Desactivamos rele 1");
     digitalWrite(RELE_1_PIN, HIGH);
  }
 
}
void rele2(bool activo)
{
  if (activo)
  {
     Serial.println("Activamos rele 2");
     digitalWrite(RELE_2_PIN, LOW);
  }
  else
  {
     Serial.println("Desactivamos rele 2");
     digitalWrite(RELE_2_PIN, HIGH);
  }
 
}
