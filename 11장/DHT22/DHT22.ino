#include "DHT.h"
#define DHT22_PIN 5
dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read22(DHT22_PIN);
  if (chk == DHTLIB_OK)
    Serial.print("OK, \t");
  else 
    Serial.print("Error, \t");
  
  Serial.print(DHT.humidity, 1);
  Serial.print(DHT.temperature, 1);
  Serial.println();

  delay(1000);
}
