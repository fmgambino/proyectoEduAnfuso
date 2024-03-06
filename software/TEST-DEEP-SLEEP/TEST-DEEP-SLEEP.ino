<<<<<<< HEAD
/*
   Ejemplo de funcionamiento básico del modo ESP8266 deep sleep
*/
 
void setup() {
  Serial.begin(115200);
 
  // Esperara a que se inicie el monitor serie
  while (!Serial) { }
 
  /*
     Aquí iría el código para obtener los valores de un sensor y
     enviar la información alguna plataforma en la nube por ejemplo.
 
     Lo que viene a continuación es una simulación.
  */
  Serial.println(" ");
  Serial.println("Temperatura: 25,5ºC");
  delay(1000);
  Serial.println("Conectando red WiFi...");
  delay(1000);
  Serial.println("Enviando información a ThingSpeak");
  delay(1000);
 
  Serial.println("Modo ESP8266 deep sleep durante 10 segundos");
  ESP.deepSleep(20e6); // 10e6 es 10.000.000 microsegundos
 
  Serial.println("Esto nunca se mostrará por el monitor serie");
}
 
void loop() {
}
=======
/*
   Ejemplo de funcionamiento básico del modo ESP8266 deep sleep
*/
 
void setup() {
  Serial.begin(115200);
 
  // Esperara a que se inicie el monitor serie
  while (!Serial) { }
 
  /*
     Aquí iría el código para obtener los valores de un sensor y
     enviar la información alguna plataforma en la nube por ejemplo.
 
     Lo que viene a continuación es una simulación.
  */
  Serial.println(" ");
  Serial.println("Temperatura: 25,5ºC");
  delay(1000);
  Serial.println("Conectando red WiFi...");
  delay(1000);
  Serial.println("Enviando información a ThingSpeak");
  delay(1000);
 
  Serial.println("Modo ESP8266 deep sleep durante 10 segundos");
  ESP.deepSleep(20e6); // 10e6 es 10.000.000 microsegundos
 
  Serial.println("Esto nunca se mostrará por el monitor serie");
}
 
void loop() {
}
>>>>>>> ec84c6f (Update Firmware MQ135.)
