unsigned long duration;
int photoInterruptorPin = 2;
unsigned long before = 0;
unsigned long period = 0;
double pi = 3.14;
double length = 0.5;
void setup() 
{
  pinMode (photoInterruptorPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  duration = pulseIn(photoInterruptorPin, LOW);
  if (duration > 0) {
   period = (millis() - before) * 2;
   Serial.println(4*pi*pi*length*1000*1000 / pow(period,2));
   before = millis();
  }
  delay(500); 
}
