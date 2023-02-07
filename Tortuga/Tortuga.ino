#include <Servo.h>
#define Trigger 3
#define Echo  4
// Define las llantas
#define LlantaIA  7
#define LlantaIR  6
#define LlantaDA  5
#define LlantaDR  4
//Define los sensores
#define Si 13
#define Sc 12
#define Sd 11

//variables
int sA, sB, sC;
int velocidad = 0;
int Estabilizador = 0;
int Graduador, Referencia;
unsigned long Tiempo;
int Centraliza = 0;
int Direccion = 0;
//velocidad
#define PwmI 10
#define PwmD 9

bool moveU = false;
bool moveD = false;
bool moveC = true;
bool moveR = false;
bool moveL = false;

Servo jkr;
int Distancia;

void setup() {
  //para el sensor ultrasonido
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(A0, INPUT);
  //para las llantas
  pinMode(LlantaIA, OUTPUT);
  pinMode(LlantaIR, OUTPUT);
  pinMode(LlantaDA, OUTPUT);
  pinMode(LlantaDR, OUTPUT);
  //para los sensores
  pinMode(Si, INPUT);
  pinMode(Sc, INPUT);
  pinMode(Sd, INPUT);
  //configuracion pwm
  pinMode(PwmI, OUTPUT);
  pinMode(PwmD, OUTPUT);
  //Velocidad de comunicacion
  Serial.begin(9600);
  //jkr.attach(3);
  //jkr.write(90);
}

void loop() {
  if (Serial.available()>0) {
    char caracter = Serial.read();
    // Detenerse
    if (caracter == 's') {
      moveC = true;
      moveU = false;
      moveD = false;
      moveR = false;
      moveL = false;
      }
     // Derecha
     if (caracter == 'd') {
      moveC = false;
      moveU = false;
      moveD = false;
      moveR = true;
      moveL = false;
      }
      // Izquierda
     if (caracter == 'i') {
      moveC = false;
      moveU = false;
      moveD = false;
      moveR = false;
      moveL = true;
      }
      // Avanzar
      if (caracter == 'a') {
      moveC = false;
      moveU = true;
      moveD = false;
      moveR = false;
      moveL = false;
      }
      // Retroceder
      if (caracter == 'r') {
      moveC = false;
      moveU = false;
      moveD = true;
      moveR = false;
      moveL = false;
      }
    }
  // Leer los sensores
  sA = digitalRead(Si);
  sB = digitalRead(Sc);
  sC = digitalRead(Sd);

  if (moveU) {
    analogWrite(PwmI,60);
    analogWrite(PwmD,60);
    digitalWrite(LlantaIA, HIGH);
    digitalWrite(LlantaIR, LOW);

    digitalWrite(LlantaDA, HIGH);
    digitalWrite(LlantaDR, LOW);
    }
  if (moveD) {
    analogWrite(PwmI,60);
    analogWrite(PwmD,60);
    digitalWrite(LlantaIA, LOW);
    digitalWrite(LlantaIR, HIGH);

    digitalWrite(LlantaDA, LOW);
    digitalWrite(LlantaDR, HIGH);
    }
  if (moveC) {
    digitalWrite(LlantaIA, LOW);
    digitalWrite(LlantaIR, LOW);

    digitalWrite(LlantaDA, LOW);
    digitalWrite(LlantaDR, LOW);
    }
  
  if (moveR) {
    analogWrite(PwmI,100);
    analogWrite(PwmD,20);
    digitalWrite(LlantaIA, HIGH);
    digitalWrite(LlantaIR, LOW);

    digitalWrite(LlantaDA, LOW);
    digitalWrite(LlantaDR, HIGH);
    }
  if (moveL) {
    analogWrite(PwmI,20);
    analogWrite(PwmD,100);
    digitalWrite(LlantaIA, LOW);
    digitalWrite(LlantaIR, HIGH);

    digitalWrite(LlantaDA, HIGH);
    digitalWrite(LlantaDR, LOW);
    }
}
