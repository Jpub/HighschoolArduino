#include <Servo.h>

Servo servo1;
int servoport = 13;
float angle = 0;
int cdsport = A0;
int value;
int MINcds = 1024;
float MINangle;
float h = 27.2, w = 59, d = 6.4;
float y1, y2, n;

void setup(){
    pinMode(cdsport, INPUT);
    servo1.attach(servoport);
    Serial.begin(9600);
}

void loop(){
   Serial.println("wait");
   for(angle=0;angle<=90;angle+=0.1){
       value=analogRead(cdsport);
       servo1.write(angle);
       delay(10);
       if(value<MINcds){
           MINangle=angle;
           MINcds=value;
       }
   }
   
   y1 = d*tan(MINangle*PI/180);
   y2 = h-y1;
   n=sin(MINangle*PI/180)*sqrt(sq(w)+sq(y2))/(y2);
   
   Serial.println();
   Serial.print("angle : ");
   Serial.println(MINangle);
   
   Serial.print("CDS : ");
   Serial.println(MINcds);
   
   Serial.print("n : ");
   Serial.println(n);
   
   Serial.println("");
   delay(1000);   
}
