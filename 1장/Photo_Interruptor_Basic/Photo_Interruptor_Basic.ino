int photoInterruptorPin = 2;

void setup() 
{
  pinMode(photoInterruptorPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  int result = digitalRead(photoInterruptorPin);
 Serial.println(result);
 delay(50);
}
