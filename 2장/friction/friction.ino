#include <Servo.h>
#include <math.h>
#define pi 3.14159265358979

float angle;
Servo servo1;

void setup()
{
  Serial.begin(9600);
  servo1.attach(9); 
}
void loop()
{
  for(angle=0; angle<90; angle = angle + 0.5)
  {
    servo1.write(angle);
    delay(100);
    if (analogRead(A0)>40)
    {
      Serial.print("angle: ");
      Serial.println(angle);
      Serial.print("u: ");
      double mu=tan((angle)*pi/180);
      Serial.println(mew);
      delay(100);
      exit(0);
    }
  }
}
