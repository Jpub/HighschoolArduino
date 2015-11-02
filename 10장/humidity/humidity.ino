#include <DHT11.h>

int pin=A0;

DHT11 dht11(pin); 
 
void setup()
{
  Serial.begin(9600);
  
  pinMode(0, OUTPUT);
}

void loop()
{
  digitalWrite(0, HIGH);

  
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(60000); 
}
