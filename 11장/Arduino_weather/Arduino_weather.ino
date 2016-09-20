#include "dht.h"
#define WIND_N    0 //정 북향
#define WIND_NNE  22.5
#define WIND_NE    45
#define WIND_ENE  67.5
#define WIND_E    90  //정 동향
#define WIND_ESE  112.5
#define WIND_SE    135
#define WIND_SSE  157.5
#define WIND_S    180
#define WIND_SSW  202.5
#define WIND_SW   225
#define WIND_WSW  247.5
#define WIND_W    270
#define WIND_WNW  292.5
#define WIND_NW   315
#define WIND_NNW  337.5
#define DHT22_PIN 5
dht DHT;

char msg[100] = "";
const int windVanePin = A0;  
int winVaneValue = 0;      
float windSpeed = 0;
float rainGauge = 0;
float windDirection = 0;
char windName[4];  
unsigned long windSpeedTimer;
int windSpeedState = true; 
int windSpeedPin = 4;
int windSpeedCounter = 0;
int rainGaugeState = true; 
int rainGaugePin = 3;
int rainGaugeCounter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(windSpeedPin, INPUT);
  digitalWrite( windSpeedPin, HIGH);
  pinMode(rainGaugePin, INPUT);
  digitalWrite( rainGaugePin, HIGH);
}

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


void loop(){
 
  Serial.print("DHT22,");
  int chk = DHT.read22(DHT22_PIN);
  switch (chk) {
    case DHTLIB_OK: 
      Serial.print("OK,"); 
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.print("Checksum error, ,"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.print("Time out error, ,"); 
      break;
    default: 
      Serial.print("Unknown error, ,"); 
      break;
  }
  
  // DISPLAY DATA
  Serial.print("Humidity,");
  Serial.print(DHT.humidity, 1);
  Serial.print(",");
  Serial.print("Temperature,");
  Serial.print(DHT.temperature, 1);
  Serial.println("");

  delay(1000);

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
    if( (rainGaugeState == true ) && !digitalRead( rainGaugePin) ){ 
      rainGaugeCounter++;     
      rainGaugeState = false;
    }else if( (rainGaugeState == false) && digitalRead(rainGaugePin) ){
      rainGaugeState = true;
    }        
  }
 rainGauge = rainGaugeCounter * 0.2794;
 windSpeed = windSpeedCounter * 0.24 ;
 
    
  getWindDirection();  
  sprintf( msg, "ArtRobot's Weather Bot said => WindDirection: %s/%d.%d WindSpeed: %d.%d(km/h) Rain %d.%d(mm/h)", windName, f2h(windDirection), f2p(windDirection), f2h(windSpeed), f2p(windSpeed),  f2h(rainGauge), f2p(rainGauge) );
  printChars( msg, sizeof(msg) ); 
}

void getWindDirection(void){
  int readValue = analogRead(windVanePin);            
  winVaneValue = map(readValue, 0, 1023, 0, 500);   
  if( winVaneValue < 35){ 
    windDirection = WIND_ESE;
    strcpy(windName ,"ESE");        
  }else if( winVaneValue < 43 ){
    windDirection = WIND_ENE;
    strcpy(windName , "ENE");        
  }else if( winVaneValue < 50 ){
    windDirection = WIND_E;
    strcpy(windName , "E");        
  }else if( winVaneValue < 70 ){
    windDirection = WIND_SSE;
    strcpy(windName , "SSE");        
  }else if( winVaneValue < 100 ){
    windDirection = WIND_SE;  
    strcpy(windName , "SE");        
  }else if( winVaneValue < 130 ){
    windDirection = WIND_SSW;  
    strcpy(windName , "SSW");        
  }else if( winVaneValue < 170 ){
    windDirection = WIND_S;  
    strcpy(windName , "S");        
  }else if( winVaneValue < 210 ){
    windDirection = WIND_NNE;  
    strcpy(windName , "NNE");            
  }else if( winVaneValue < 250 ){
    windDirection = WIND_NE;  
    strcpy(windName , "NE");            
  }else if( winVaneValue < 300 ){
    windDirection = WIND_WSW;  
    strcpy(windName , "WSW");        
  }else if( winVaneValue < 320 ){
    windDirection = WIND_SW;  
    strcpy(windName , "SW");        
  }else if( winVaneValue < 360 ){
    windDirection = WIND_NNW;  
    strcpy(windName , "NNW");        
  }else if( winVaneValue < 395 ){
    windDirection = WIND_N;  
    strcpy(windName , "N");
  }else if( winVaneValue < 415 ){
    windDirection = WIND_WNW;  
    strcpy(windName , "WNW");    
  }else if( winVaneValue < 450 ){
    windDirection = WIND_NW;  
    strcpy(windName , "NW");        
  }else if( winVaneValue < 490 ){
    windDirection = WIND_W;  
    strcpy(windName , "W");        
  }
}
