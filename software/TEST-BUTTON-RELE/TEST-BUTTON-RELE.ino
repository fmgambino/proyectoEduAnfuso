const int RX = 1;   // Entrada Digital
const int D5 = 2; // Rele 1

const int SD3 = 10;   // Entrada Digital
const int D4 = 14; // Rele 2

int val;
int val1;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);

  pinMode(D5, OUTPUT);
  pinMode(RX, INPUT);
  pinMode(D4, OUTPUT);
  pinMode(SD3, INPUT);
 digitalWrite(SD3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  //digitalWrite(RX, LOW);
  
  val=digitalRead(RX);
  val1=digitalRead(SD3);
  
  //Serial.print("Val: ");
  //Serial.println(val);
  
  if  (val==HIGH){
    digitalWrite(D5,HIGH);
  }
  else { digitalWrite(D5,LOW);
}

  if  (val1==HIGH){
    digitalWrite(D4,LOW);
  }
  else { digitalWrite(D4,HIGH);
}
}
