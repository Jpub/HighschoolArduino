#include <Wire.h>
#define address 0x1E

void setup(){
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(address);
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission();
}

void loop(){
  int x,y,z;
  Wire.beginTransmission(address);
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8;
    x |= Wire.read();
    z = Wire.read()<<8;
    z |= Wire.read();
    y = Wire.read()<<8;
    y |= Wire.read();
  }
  Serial.println(z);
  delay(250);
}
