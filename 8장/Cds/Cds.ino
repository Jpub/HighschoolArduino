int value;
int cdsport = A0;

void setup(){
    pinMode(cdsport, INPUT);
    Serial.begin(9600); 
}

void loop(){
  value = analogRead(cdsport);
  Serial.print("CDS :");
  Serial.println(value);
  delay(100);
}
