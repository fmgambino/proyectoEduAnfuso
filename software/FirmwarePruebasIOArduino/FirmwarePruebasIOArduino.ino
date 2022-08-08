int t1=250;

// inputs
/*const int io14 = 14;
const int io12 = 12;
const int io1 = 1;
const int io3 = 3;
const int in4 = 32;
const int in5 = 33;
const int in6 = 26;
const int in7 = 25;*/

// outputs
const int D1 = 5; 
const int D2 = 2;
const int D5 = 11;
const int D6 = 9;
const int D7 = 10;

/*const int ot6 = 18;
const int ot7 = 19;
const int ot8 = 23; */

void setup() {
   /*pinMode(io14, INPUT);
  pinMode(io12, INPUT);
  pinMode(io1, INPUT);
  pinMode(io3, INPUT);
 pinMode(in4, INPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT); */

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT); 


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

  digitalWrite(D1, LOW);
  delay(t1);
  digitalWrite(D1, HIGH);
  delay(t1);
  
  


  /*if (digitalRead(in6))digitalWrite(ot6, 1);
  else digitalWrite(ot6, 0);
  if (digitalRead(in7))digitalWrite(ot7, 1);
  else digitalWrite(ot7, 0);
  if (digitalRead(in8))digitalWrite(ot8, 1);
  else digitalWrite(ot8, 0);*/
}
