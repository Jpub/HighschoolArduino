#include <Servo.h>

Servo servo1;
int servoport = 13;
int angle = 0;

void setup(){   
  servo1.attach(servoport);
}
 
void loop(){

  for(angle = 0; angle <= 90; angle++){
    servo1.write(angle);  
    delay(100);
  }
}
