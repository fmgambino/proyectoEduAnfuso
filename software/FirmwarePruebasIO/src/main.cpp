#include <Arduino.h>

int sensor = A0;
int mq;
int co2lvl = 0;
int buzer = 2 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(buzer, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(buzer, LOW);
  mq = analogRead(sensor);

  co2lvl = mq - 120;
  co2lvl = map(co2lvl, 0, 1024, 400, 5000);
  Serial.print("Valor Analogo: ");
  Serial.println(co2lvl);
  delay(1000);

   if ((co2lvl < 750) )
  {
    Serial.println(" Bajo ");
    digitalWrite(buzer, LOW);
  }
   else
  {
    Serial.println(" NIVEL ALTO CO2");
    digitalWrite(buzer, HIGH);
  }
}