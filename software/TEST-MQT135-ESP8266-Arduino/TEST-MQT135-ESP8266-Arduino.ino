int sensor = A0;
int red = 6;


int gas, co2lvl;

void setup() { 
  
  pinMode(red, OUTPUT);  
  pinMode(sensor, INPUT);
  Serial.begin(115200);  
}


void loop() {

  gas = analogRead(sensor);
  co2lvl = gas - 120;
  co2lvl = map(co2lvl, 0, 1024, 400, 5000);
 
  
  Serial.print("CO2: "); 
  Serial.print(co2lvl);
  Serial.print(" ppm");
  if ((co2lvl < 350) )
  {
    Serial.println(" Bajo ");
    digitalWrite(red, LOW);
  }
  if ((co2lvl >= 350) && (co2lvl <= 1400))
  {
    Serial.println(" Bueno ");
    digitalWrite(red, LOW);
  }
  if ((co2lvl >= 1400) && (co2lvl <= 2000))
  {
    digitalWrite(red, HIGH);
    Serial.println("  Alto "); 
  }
  if (co2lvl > 2000)
  {
    Serial.println(" Peligro!");
    digitalWrite(red, HIGH);
  }
  delay(300);  
}
