#define SensorPin 0  
#define PhotoPin 2
#define OFFSET 0.00
int count = 0;

void setup(){
  pinMode(PhotoPin, INPUT);
  Serial.begin(9600);  
}

void loop(){

  while (digitalRead(PhotoPin));
  while (!digitalRead(PhotoPin)); 

  count ++;

  int SensorValue = analogRead(SensorPin); 
  float phValue=(float)SensorValue * 5.0 / 1024; 
  phValue = (phValue * 3.5) + OFFSET;
  Serial.print(count);  
  Serial.print(" ");
  Serial.println(phValue,2);

}



