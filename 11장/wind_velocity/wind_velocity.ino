unsigned long windSpeedTimer;
int windSpeedState = true; 
int windSpeedPin = 4;
int windSpeedCounter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(windSpeedPin, INPUT);
  digitalWrite( windSpeedPin, HIGH);
}

void loop() {
  windSpeedTimer = millis() + 10000; 
  windSpeedCounter = 0;
  while( millis() < windSpeedTimer ){
    delay(20);  
    if( (windSpeedState == true ) && !digitalRead( windSpeedPin) ){ 
      windSpeedCounter++;     
      windSpeedState = false;
    }else if( (windSpeedState == false) && digitalRead(windSpeedPin) ){
      windSpeedState = true;
    }            
  }
  windSpeed = windSpeedCounter * 0.24;
  Serial.print(windSpeed);
  Serial.print("(km/h)");
  Serial.println(); 
}
