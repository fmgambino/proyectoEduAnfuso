#define MQ135_PIN 36

void setup() {
  // Inicializamos la serial
  Serial.begin(115200);
}

void loop() {
  // Realizamos la lectura
  int lectura = analogRead(MQ135_PIN);

  // Imprimimos la lectura
  Serial.println(lectura);

  // Esperamos 1 segundo
  delay(1000);
}
