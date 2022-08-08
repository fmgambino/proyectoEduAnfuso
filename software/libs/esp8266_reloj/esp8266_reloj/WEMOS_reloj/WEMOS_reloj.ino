#include <ESP8266WiFi.h>
#include <WifiUDP.h>
#include <NTPClient.h>
#include <Time.h>
#include <TimeLib.h>
#include <Timezone.h>


// Configurar wifi
const char* ssid = "JUAREZ";                                                                                                 // añade tu ssid 
const char* password = "CAROLINA342";                                                                                          // añade tu password

// Definir propiedades NTP
#define NTP_OFFSET   60 * 60                                                                                               // En segundos
#define NTP_INTERVAL 60 * 1000                                                                                             // En milisegundos
#define NTP_ADDRESS  "pool.ntp.org"                                                                                        // URL NTP

WiFiUDP ntpUDP;                                                                                                            // Configura el cliente NTP UDP 
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 60};                                                                     // Hora de Verano de Europa Central
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 0};                                                                       // Hora Estandar de Europa Central
Timezone CE(CEST, CET);
time_t local, utc;

const char * days[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"} ;                        // Configurar Fecha y hora
const char * months[] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"} ;            // Configurar Fecha y hora


void setup() 
{
  Serial.begin(9600);                                                                                                     // Inicializar puerto serie
  Serial.println("");
  Serial.print("conectando a ");                                                                                           // Mostramos por puerto serie el nombre de la wifi a conectarse
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)                                                                                    // Esperamos hasta que haya conexion con la wifi.  
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectando WiFi a ");                                                                                    // Mostramos la ip que nos ha asignado el router.
  Serial.print(WiFi.localIP());                                                          
  Serial.println("");
}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED)                                                                                    // Estamos conectados ?
  {   
    timeClient.update();                                                                                                // Actualizar el cliente NTP y obtener la marca de tiempo UNIX UTC
    unsigned long utc =  timeClient.getEpochTime();
    local = CE.toLocal(utc);                                                                                            // Convertir marca de tiempo UTC UNIX a hora local
    printTime(local);                                                                                                   // Enviar Fecha y hora por puerto serie
  }
  else {                                                                                                                // Intenta conectarse a wifi de nuevo si está desconectado
    WiFi.begin(ssid, password);
    delay(1000);
  }
  delay(10000);    // Enviar una solicitud para actualizar cada 10 seg (= 10,000 ms)
}

void printTime(time_t t)                                                                                              // Funcion para mandar hora por puerto serie    
{
  Serial.println("");
  Serial.print("Fecha local: ");
  Serial.print(convertirTimeATextoFecha(t));
  Serial.println("");
  Serial.print("Hora local: ");
  Serial.print(convertirTimeATextoHora(t));
}

String convertirTimeATextoFecha(time_t t)                                                                               // Funcion para formatear en texto la fecha  
{
  String date = "";
  date += days[weekday(t)-1];
  date += ", ";
  date += day(t);
  date += " ";
  date += months[month(t)-1];
  date += ", ";
  date += year(t);
  return date;
}

String convertirTimeATextoFechaSinSemana(time_t t)                                                                    // Funcion para formatear en texto la fecha sin dia de la semana
{
  String date = "";
  date += months[month(t)-1];
  date += "   ";
  date += year(t);
  return date;
}

String convertirTimeATextoHora(time_t t)                                                                              // Funcion para formatear en texto la hora                                                                          
{
  String hora ="";                                                                                                    // Funcion para formatear en texto la hora  
  if(hour(t) < 10)
  hora += "0";
  hora += hour(t);
  hora += ":";
  if(minute(t) < 10)                                                                                                  // Agregar un cero si el minuto es menor de 10
    hora += "0";
  hora += minute(t);
  return hora;
}
