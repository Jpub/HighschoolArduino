#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Servo.h>

Adafruit_INA219 ina219;
Servo myservo;
int val;

void setup(void) 
{
  uint32_t currentFrequency;
  myservo.attach(9);
  Serial.begin(115200);
  ina219.begin();
}

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  
  for(val=30; val<=150; val++){
    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print(current_mA*loadvoltage);
  Serial.print(' ');
  myservo.write(val);
  Serial.println(val);
  delay(200);
  }
  exit(0);
}
