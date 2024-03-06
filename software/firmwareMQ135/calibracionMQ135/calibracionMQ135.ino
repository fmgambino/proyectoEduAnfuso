#include <Arduino.h>

#define MQ135_PIN 36

#define SENSIBILIDAD_CO_CALIBRADO 600
#define SENSIBILIDAD_NH3_CALIBRADO 200

void setup() {
  Serial.begin(115200);
 // pinMode(MQ135_PIN, INPUT_ANALOG);
}

void loop() {
  int lectura_aire_limpio = analogRead(MQ135_PIN);
  float Ro = (lectura_aire_limpio * 5.0) / 1023.0;

  // Calcular la sensibilidad para CO
  float sensibilidad_co = SENSIBILIDAD_CO_CALIBRADO / Ro;

  // Calcular la sensibilidad para NH3
  float sensibilidad_nh3 = SENSIBILIDAD_NH3_CALIBRADO / Ro;

  Serial.print("Sensibilidad CO: ");
  Serial.print(sensibilidad_co);
  Serial.print(" | Sensibilidad NH3: ");
  Serial.println(sensibilidad_nh3);

  delay(1000);
}
