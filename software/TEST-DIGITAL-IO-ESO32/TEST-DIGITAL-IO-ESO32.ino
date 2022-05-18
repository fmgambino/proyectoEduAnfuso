int t1=200;
int t2 = 500;

int d1= 5;
int d2= 4;

// inputs
int d0 = 16;  // clk
int d3 = 0;   // D4
int d4 = 2;  // cmd
int cmd = 11;  // s3 
int sd0 = 7;   // s2
int sd1 = 8;  // s3 
int sd2 = 9;  // s3 
int sd3 = 10;  // s3 
int rx = 3;  // s3 

// outputs

int d5 = 14;  // clk
int d6 = 12;   // D4
int d7 = 13;  // RELE 3
int d8 = 15;   // WI-FI RST
int tx = 1;  // s3


void setup() {

  pinMode(d0, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(d5, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(d6, OUTPUT);
  pinMode(d7, OUTPUT);
  pinMode(d8, OUTPUT);
//  pinMode(tx, INPUT);
//  pinMode(rx, INPUT);
//pinMode(cmd, OUTPUT);
//pinMode(sd0, OUTPUT);
//pinMode(sd1, OUTPUT);
//pinMode(sd2, INPUT);
//pinMode(sd3, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {

digitalWrite(d0, LOW);
digitalWrite(d1, LOW);
digitalWrite(d2, LOW);
digitalWrite(d3, LOW);
digitalWrite(d4, LOW);
digitalWrite(d5, LOW);
digitalWrite(d6, LOW);
digitalWrite(d7, LOW);
digitalWrite(d8, LOW);
//digitalWrite(tx, LOW);
//digitalWrite(rx, LOW);
/*
  digitalWrite(d0, LOW);
  delay(t1);
  digitalWrite(d0, HIGH);
  delay(t2);

  digitalWrite(d1, LOW);
  delay(t1);
  digitalWrite(d1, HIGH);
  delay(t2);

  digitalWrite(d2, LOW);
  delay(t1);
  digitalWrite(d2, HIGH);
  delay(t2);
*/
  digitalWrite(d3, HIGH);
  delay(t1);
  digitalWrite(d3, LOW);
  delay(t2);

  digitalWrite(d4, HIGH);
  delay(t1);
  digitalWrite(d4, LOW);
  delay(t2);
/*
  digitalWrite(d5, LOW);
  delay(t1);
  digitalWrite(d5, HIGH);
  delay(t2);
*/
  digitalWrite(d6, LOW);
  delay(t1);
  digitalWrite(d6, HIGH);
  delay(t2);
/*
  digitalWrite(d7, LOW);
  delay(t1);
  digitalWrite(d7, HIGH);
  delay(t2);
*/
  digitalWrite(d8, LOW);
  delay(t1);
  digitalWrite(d8, HIGH);
  delay(t2);
/*  
  digitalWrite(tx, LOW);
  delay(t1);
  digitalWrite(tx, HIGH);
  delay(t2);

  digitalWrite(rx, LOW);
  delay(t1);
  digitalWrite(rx, HIGH);
  delay(t2);

  digitalWrite(sd2, LOW);
  delay(t1);
  digitalWrite(sd2, HIGH);
  delay(t1); 
*/
  digitalWrite(sd3, LOW);
  delay(t1);
  digitalWrite(sd3, HIGH);
  delay(t2);
/*  
  digitalWrite(cmd, LOW);
  delay(t1);
  digitalWrite(cmd, HIGH);
  delay(t1);
  
  digitalWrite(sd0, LOW);
  delay(t1);
  digitalWrite(sd0, HIGH);
  delay(t1);

  digitalWrite(sd1, LOW);
  delay(t1);
  digitalWrite(sd1, HIGH);
  delay(t1);
*/
}
