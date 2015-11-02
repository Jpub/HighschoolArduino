#include <Wire.h>
#define address 0x1E

void setup(){
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(address);
  Wire.send(0x02);
  Wire.send(0x00);
  Wire.endTransmission();
}

void loop(){
 
  int x,y,z;

  Wire.beginTransmission(address);
  Wire.send(0x03);
  Wire.endTransmission();
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.receive()<<8;
    x |= Wire.receive();
    z = Wire.receive()<<8;
    z |= Wire.receive();
    y = Wire.receive()<<8;
    y |= Wire.receive();
  }

  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);
 
  delay(250);
}
