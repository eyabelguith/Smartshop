// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   
#define LedR 11
#define LedB A0
DHT dht(DHTPIN, DHTTYPE);

char data;

void setup() {
  
  Serial.begin(9600);
  pinMode (LedR, OUTPUT);
  analogWrite (LedR, 0);
  pinMode (LedB, OUTPUT);
  analogWrite (LedB, 0);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);

  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(t); //envoyer la temperature comme data


  
if(Serial.available()>0)
{
  data=Serial.read();//recevoir data reponse
  
   if(data=='1')
   {
      digitalWrite(LedR , HIGH);
      digitalWrite(LedB , LOW);
   }
   else if(data=='0'){
                       digitalWrite(LedR , LOW);
                       digitalWrite(LedB , HIGH);
                     }
        else
            {
               digitalWrite(LedR , LOW);
               digitalWrite(LedB , LOW);
            }
}        

}
