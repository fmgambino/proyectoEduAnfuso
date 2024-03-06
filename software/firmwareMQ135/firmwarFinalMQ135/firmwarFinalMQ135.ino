#include <Arduino.h>
#include <math.h>
#include <EEPROM.h>

#define PIN_SENSOR A0

// Constantes para la ecuación de la recta tangente
#define CO_A 0.5
#define CO_B 0.004
#define NH3_A 0.6
#define NH3_B 0.006

// Variables para almacenar datos
float co_ppm[1000];
float nh3_ppm[1000];

float Ro;

// Función para calibrar el sensor
void calibrarSensor(int pin, float a, float b) {
  // Leer la resistencia en aire limpio
  Ro = analogRead(pin);

  // Calcular la constante de sensibilidad
  float alpha = (1 / b) * log(Ro / (Ro - a));

  // Almacenar la constante de sensibilidad en la EEPROM
  EEPROM.write(0, alpha);
}

// Función para medir la concentración de gas en ppm
float medirPPM(int pin, float a, float b) {
  // Leer la resistencia en presencia del gas
  float rs = analogRead(pin);

  // Calcular la concentración de gas en ppm
  float ppm = ((rs / Ro) - a) / b;

  // Devolver la concentración de gas en ppm
  return ppm;
}

// Función para calcular la media de un array de valores
float calcularPromedio(float array[], int muestras) {
  float suma = 0;

  for (int i = 0; i < muestras; i++) {
    suma += array[i];
  }

  float promedio = suma / muestras;

  return promedio;
}

void setup() {
  // Inicializa el puerto serie
  Serial.begin(115200);

  // Calibrar el sensor
  calibrarSensor(PIN_SENSOR, CO_A, CO_B);
  calibrarSensor(PIN_SENSOR, NH3_A, NH3_B);
}

void loop() {
  // Variable para el tamaño del array
  int muestras = 1000;

  // Tomar 1000 muestras
  for (int i = 0; i < muestras; i++) {
    co_ppm[i] = medirPPM(PIN_SENSOR, CO_A, CO_B);
    nh3_ppm[i] = medirPPM(PIN_SENSOR, NH3_A, NH3_B);
  }

  // Calcular la media de las muestras
  float co_promedio = calcularPromedio(co_ppm, muestras);
  float nh3_promedio = calcularPromedio(nh3_ppm, muestras);

  // Imprimir los datos por puerto serie
  Serial.print("CO (ppm): ");
  Serial.print(co_promedio);
  Serial.print(" | NH3 (ppm): ");
  Serial.println(nh3_promedio);

  // Esperar un segundo antes de la siguiente medición
  delay(1000);
}
