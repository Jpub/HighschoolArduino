char msg[100] = "";

void printChars(char *msg, int len){
  if(len == 0) return;
  for(int i=0; i<len;  i++)
    Serial.print( msg[i]);
  Serial.println();
}

int f2h( float num){
  return int(num);
}

int f2p( float num){
  return (num - int(num)) * 100;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  sprintf(msg, "Direction: %s/%d.%d",
       windName, f2h(windDirection), f2p(windDirection) );
  printChars( msg, sizeof(msg) ); 
}
