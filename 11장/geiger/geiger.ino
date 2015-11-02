#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);

#define CONV_FACTOR 0.00812

const int geiger_input = 2;
long count = 0;
long countPerMinute = 0;
long timePreviousMeassure = 0;
float radiationValue = 0.0;

void setup(){
  pinMode(geiger_input, INPUT);
  digitalWrite(geiger_input,HIGH);

  Serial.begin(19200);

  attachInterrupt(0,countPulse,FALLING);
}

void loop(){
  if (millis() - timePreviousMeassure > 10000){
    countPerMinute = 6 * count;
    radiationValue = countPerMinute * CONV_FACTOR;
    
    timePreviousMeassure = millis();

    Serial.print("cpm = "); 
    Serial.print(countPerMinute,DEC);
    Serial.print(" - ");
    Serial.print("uSv/h = ");
    Serial.println(radiationValue,4);      
    lcd.clear();    
    lcd.setCursor(0, 0);
    lcd.print("CPM=");
    lcd.setCursor(4,0);
    lcd.print(countPerMinute);
    lcd.setCursor(0,1);
    lcd.print(radiationValue,4);
    lcd.setCursor(6,1);
    lcd.print(" uSv/h");

    count = 0;
  }
}

void countPulse(){
  detachInterrupt(0);

  count++;
  while(digitalRead(2)==0);

  attachInterrupt(0,countPulse,FALLING);
}
