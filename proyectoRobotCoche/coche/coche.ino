#include <NewPing.h>
//MOTORES
const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;
const int pinIN3 = 9;
const int pinIN4 = 10;
const int pinENB = 11;
const int speed = 200;      //velocidad de giro

const int pinMotorD[3] = { pinENA, pinIN1, pinIN2 };  //Motor derecho
const int pinMotorI[3] = { pinENB, pinIN3, pinIN4 };  //Motor Izquierdo

//PROXIMIDAD
const int TRIGGER_PIN = 5;
const int ECHO_PIN = 4;
const int MAX_DISTANCE = 200;  // Distancia máxima que podrá medir el sensor.
const int distanciaMinima = 10; //Centimetros minimo a lo que nos acercamos

//Constantes auxiliares
const int waitTime = 2000;   //espera entre fases

//Funcion encargada de detectar los obstaculos
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup()
{
   pinMode(pinIN1, OUTPUT);
   pinMode(pinIN2, OUTPUT);
   pinMode(pinENA, OUTPUT);
   pinMode(pinIN3, OUTPUT);
   pinMode(pinIN4, OUTPUT);
   pinMode(pinENB, OUTPUT);
}
 
void loop()
{
   //Comprobamos si tenemos obstaculo
   if (sonar.ping_cm()<distanciaMinima)
   {
     //NO TENEMOS OBSTACULO: Nos movemos hacia adelante   
     moverAdelante(pinMotorD, 180);
     moverAdelante(pinMotorI, 180);
   }
   else
   { //Nos paramos
     paramos(pinMotorD);
     paramos(pinMotorI);
     delay(waitTime);

     //TODO: Giramos
     
     //Movemos hacia atras
     //moverAtras(pinMotorD, 180);
     //moverAtras(pinMotorI, 180);
   }
   delay(waitTime);
}
 
void moverAdelante(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], HIGH);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], speed);
}
 
void moverAtras(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], HIGH);
 
   analogWrite(pinMotor[0], speed);
}
 
void paramos(const int pinMotor[3])
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], 0);
}
