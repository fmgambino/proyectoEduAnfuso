<<<<<<< HEAD
int D8 = 15;
int D4 = 2;
int val;

void setup() {
 
  pinMode(D8, INPUT_PULLUP);
  pinMode(D4, OUTPUT);

}

void loop() {

  val=digitalRead(D8);

  if  (val==HIGH){
    digitalWrite(D4,HIGH);
    }
  else { digitalWrite(D4,LOW);
  }
  
}
=======
int D8 = 15;
int D4 = 2;
int val;

void setup() {
 
  pinMode(D8, INPUT_PULLUP);
  pinMode(D4, OUTPUT);

}

void loop() {

  val=digitalRead(D8);

  if  (val==HIGH){
    digitalWrite(D4,HIGH);
    }
  else { digitalWrite(D4,LOW);
  }
  
}
>>>>>>> ec84c6f (Update Firmware MQ135.)
