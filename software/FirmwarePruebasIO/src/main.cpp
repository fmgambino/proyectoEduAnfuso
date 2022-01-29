#include <Arduino.h>

// inputs
const int io14 = 14;
const int io12 = 12;
const int io01 = 1;
const int io03 = 3;
/*const int in4 = 32;
const int in5 = 33;
const int in6 = 26;
const int in7 = 25;*/

// outputs
const int q01 = 6;
const int q02 = 2;
const int q03 = 11;
const int q04 = 9;
const int Q05 = 10;
/*const int ot6 = 18;
const int ot7 = 19;
const int ot8 = 23; */

void setup() {
  pinMode(io14, INPUT);
  pinMode(io12, INPUT);
  pinMode(io01, INPUT);
  pinMode(io03, INPUT);
  /*pinMode(in4, INPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT); */

  pinMode(q01, OUTPUT);
  pinMode(q02, OUTPUT);
  pinMode(q03, OUTPUT);
  pinMode(q04, OUTPUT);
  pinMode(Q05, OUTPUT); 


 /* pinMode(ot4, OUTPUT);
  pinMode(ot5, OUTPUT);
  pinMode(ot6, OUTPUT);
  pinMode(ot7, OUTPUT);*/
}

void loop() {
 // RELAY simple test inputs and outputs 
  /*if (digitalRead(io14))digitalWrite(q01, 1);
  else digitalWrite(q01, 0);
  if (digitalRead(io12))digitalWrite(q02, 1);
  else digitalWrite(q02, 0);
  if (digitalRead(io01))digitalWrite(q03, 1);
  else digitalWrite(q03, 0);
  if (digitalRead(io03))digitalWrite(q04, 1);
  else digitalWrite(q04, 0);*/
  digitalWrite(q01, HIGH);
  delay(1500);
  digitalWrite(q01, LOW);
  delay(1500);

  digitalWrite(q02, HIGH);
  delay(1500);
  digitalWrite(q02, LOW);
  delay(1500);

  digitalWrite(q03, HIGH);
  delay(1500);
  digitalWrite(q03, LOW);
  delay(1500);

  digitalWrite(q04, HIGH);
  delay(1500);
  digitalWrite(q04, LOW);
  delay(1500);
  
  //MOSFET
  digitalWrite(Q05, HIGH);
  delay(1500);
  digitalWrite(Q05, LOW);
  delay(1500);
  /*if (digitalRead(in6))digitalWrite(ot6, 1);
  else digitalWrite(ot6, 0);
  if (digitalRead(in7))digitalWrite(ot7, 1);
  else digitalWrite(ot7, 0);
  if (digitalRead(in8))digitalWrite(ot8, 1);
  else digitalWrite(ot8, 0);*/
}