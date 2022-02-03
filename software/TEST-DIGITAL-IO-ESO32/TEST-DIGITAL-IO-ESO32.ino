int t1=200;
int t2 = 500;

int D1= 5;
int D2= 4;

// inputs
int D0 = 16;  // clk
int D3 = 0;   // D4
int D4 = 2;  // cmd
int CMD = 11;  // s3 
int SD0 = 7;   // s2
int SD1 = 8;  // s3 
int SD2 = 9;  // s3 
int SD3 = 10;  // s3 
int RX = 3;  // s3 

// outputs

int D5 = 14;  // clk
int D6 = 12;   // D4
int D7 = 13;  // cmd
int D8 = 15;   // s2
int TX = 1;  // s3


void setup() {

  pinMode(D0, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(TX, OUTPUT);
  pinMode(RX, OUTPUT);
//pinMode(CMD, OUTPUT);
//pinMode(SD0, OUTPUT);
//pinMode(SD1, OUTPUT);
  pinMode(SD2, OUTPUT);
//pinMode(SD1, OUTPUT);
//pinMode(SD3, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {

digitalWrite(D0, LOW);
digitalWrite(D1, LOW);
digitalWrite(D2, LOW);
digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
digitalWrite(D5, LOW);
digitalWrite(D6, LOW);
digitalWrite(D7, LOW);
digitalWrite(D8, LOW);
digitalWrite(TX, LOW);
digitalWrite(RX, LOW);

  digitalWrite(D0, LOW);
  delay(t1);
  digitalWrite(D0, HIGH);
  delay(t2);

  digitalWrite(D1, LOW);
  delay(t1);
  digitalWrite(D1, HIGH);
  delay(t2);

  digitalWrite(D2, LOW);
  delay(t1);
  digitalWrite(D2, HIGH);
  delay(t2);

  digitalWrite(D3, LOW);
  delay(t1);
  digitalWrite(D3, HIGH);
  delay(t2);

  digitalWrite(D4, LOW);
  delay(t1);
  digitalWrite(D4, HIGH);
  delay(t2);

  digitalWrite(D5, LOW);
  delay(t1);
  digitalWrite(D5, HIGH);
  delay(t2);

  digitalWrite(D6, LOW);
  delay(t1);
  digitalWrite(D6, HIGH);
  delay(t2);

  digitalWrite(D7, LOW);
  delay(t1);
  digitalWrite(D7, HIGH);
  delay(t2);

  digitalWrite(D8, LOW);
  delay(t1);
  digitalWrite(D8, HIGH);
  delay(t2);
  

  digitalWrite(TX, LOW);
  delay(t1);
  digitalWrite(TX, HIGH);
  delay(t2);

  digitalWrite(RX, LOW);
  delay(t1);
  digitalWrite(RX, HIGH);
  delay(t2);
/*
  digitalWrite(CMD, LOW);
  delay(t1);
  digitalWrite(CMD, HIGH);
  delay(t1);
  
  digitalWrite(SD0, LOW);
  delay(t1);
  digitalWrite(SD0, HIGH);
  delay(t1);

  digitalWrite(SD1, LOW);
  delay(t1);
  digitalWrite(SD1, HIGH);
  delay(t1);*/
/*
  digitalWrite(SD2, LOW);
  delay(t1);
  digitalWrite(SD2, HIGH);
  delay(t1); */

  digitalWrite(SD3, LOW);
  delay(t1);
  digitalWrite(SD3, HIGH);
  delay(t2);
  
}
