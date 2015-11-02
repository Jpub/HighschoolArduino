#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

double pressure, temperature;
  
void setup() {
  Serial.begin(9600);
  while (!bmp.begin());
  Serial.println("Sensor BMP085 setup finished.");
}
  
void loop() {
    Serial.print("temperature = ");
    temperature = bmp.readTemperature() + 273.15;
    Serial.print(temperature);
    Serial.println(" K");
    
    Serial.print("Pressure = ");
    pressure = bmp.readPressure();
    Serial.print(pressure);
    Serial.println(" Pa");
    
    Serial.print("P/T = ");
    Serial.println(pressure / temperature);
    
    Serial.println();
    delay(5000);
}
