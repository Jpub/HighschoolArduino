int photoGatePin1 = 2;
int photoGatePin2 = 3;
int photoGatePin3 = 4;

unsigned long start, time1, time2;

void setup() 
{
  pinMode(photoGatePin1, INPUT);
  pinMode(photoGatePin2, INPUT);
  pinMode(photoGatePin3, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  while(digitalRead(photoGatePin1));
  start = millis();
  while(digitalRead(photoGatePin2));
  time1 = millis();
  while(digitalRead(photoGatePin3));
  time2 = millis();
  
  double T1= (time1-start)/1000.0;
  double T2= (time2-start)/1000.0;
  double V1 = (0.35 / T1)*2;
  double V2 = (0.7 / T2)*2;
  
  Serial.print("V1 : ");
  Serial.println(V1);
  Serial.print("V2 : ");
  Serial.println(V2);
  Serial.print("\n");
}
