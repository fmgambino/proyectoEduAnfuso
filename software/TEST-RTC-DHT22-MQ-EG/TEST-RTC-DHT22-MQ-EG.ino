
#include <Wire.h>   // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC
#include "DHT.h" // Libreria DHT11/22

//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

const int DHTPin = 14;     // what digital pin we're connected to

int sensor = A0;
//int red = 2;
int gas, co2lvl;

int relay1 = 10;
int relay2 = 12;
int relay3 = 15;

int bWifi = 13;
int buttonState = 0;

int ledwf   = 2;
int ledmqtt = 0;

DHT dht(DHTPin, DHTTYPE);

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

void btnWiFi();
void rtcEG();
void mqEG();

void setup () {
 Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
 Serial.println("DHTxx test by EG!");


 pinMode (bWifi, INPUT);
 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
 pinMode(relay3, OUTPUT);
 pinMode(ledwf, OUTPUT);
 pinMode(ledmqtt, OUTPUT);

 dht.begin();

 if (! rtc.begin()) {       // si falla la inicializacion del modulo
 Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
 while (1);         // bucle infinito que detiene ejecucion del programa
 }
 //rtc.adjust(DateTime(__DATE__, __TIME__));  // funcion que permite establecer fecha y horario
            // al momento de la compilacion. Comentar esta linea
            // y volver a subir el codigo para funcionamiento normal 
            
  //pinMode(red, OUTPUT);  
  pinMode(sensor, INPUT);
  Serial.begin(115200);
  
  
  }           

void loop () {
 // Wait a few seconds between measurements.
   delay(2000);

   rtcEG();
   btnWiFi();
   mqEG();
   // Reading temperature or humidity takes about 250 milliseconds!
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }


   Serial.print("Humedad: ");
   Serial.print(h);
   Serial.println(" %\t");
   Serial.print("Temperatura: ");
   Serial.print(t);
   Serial.println(" *C ");

   Serial.println(" ");

   digitalWrite(relay1,HIGH);
   delay(500);
   digitalWrite(relay1,LOW);
   delay(500);

   digitalWrite(relay2,HIGH);
   delay(500);
   digitalWrite(relay2,LOW);
   delay(500);

   digitalWrite(relay3,HIGH);
   delay(500);
   digitalWrite(relay3,LOW);
   delay(500);

   digitalWrite(ledwf,HIGH);
   delay(500);
   digitalWrite(ledwf,LOW);
   delay(500);

   digitalWrite(ledmqtt,HIGH);
   delay(500);
   digitalWrite(ledmqtt,LOW);
   delay(500);
}


void btnWiFi(){

  buttonState = digitalRead(bWifi);
  
  if (buttonState == LOW) {
    // turn LED on:
    Serial.print("BOTON WI-FI OK !!! ");
    delay(10);
  }
  
}

void rtcEG(){

 DateTime fecha = rtc.now();      // funcion que devuelve fecha y horario en formato
            // DateTime y asigna a variable fecha
 Serial.print(fecha.day());     // funcion que obtiene el dia de la fecha completa
 Serial.print("/");       // caracter barra como separador
 Serial.print(fecha.month());     // funcion que obtiene el mes de la fecha completa
 Serial.print("/");       // caracter barra como separador
 Serial.print(fecha.year());      // funcion que obtiene el año de la fecha completa
 Serial.print(" ");       // caracter espacio en blanco como separador
 Serial.print(fecha.hour());      // funcion que obtiene la hora de la fecha completa
 Serial.print(":");       // caracter dos puntos como separador
 Serial.print(fecha.minute());      // funcion que obtiene los minutos de la fecha completa
 Serial.print(":");       // caracter dos puntos como separador
 Serial.println(fecha.second());    // funcion que obtiene los segundos de la fecha completa
 
 delay(1000);         // demora de 1 segundo

}

void mqEG(){

   gas = analogRead(sensor);
  co2lvl = gas - 120;
  co2lvl = map(co2lvl, 0, 1024, 400, 5000);
 
  
  Serial.print("CO2: "); 
  Serial.print(co2lvl);
  Serial.println(" ppm");
  if ((co2lvl < 350) )
  {
    Serial.println(" Bajo ");
    //digitalWrite(red, LOW);
  }
  if ((co2lvl >= 350) && (co2lvl <= 500))
  {
    Serial.println(" Bueno ");
    //digitalWrite(red, LOW);
  }
  if ((co2lvl >= 800) && (co2lvl <= 1000))
  {
    //digitalWrite(red, HIGH);
    Serial.println("  Alto "); 
  }
  if (co2lvl > 2000)
  {
    Serial.println(" Peligro!");
    //digitalWrite(red, HIGH);
  }
  delay(300);  

}
