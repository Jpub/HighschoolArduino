#define SPEAKER 9
#define MIC 0
#define PHOTO 4
#define FREQ 5000

unsigned long volume;
int cnt_vol, cnt_drop;

void setup(){
	pinMode(PHOTO,INPUT);
	Serial.begin(9600); 
}

void loop(){
	tone(SPEAKER,FREQ,7000);
	cnt_vol = 0, volume = 0;

	while(digitalRead(PHOTO));
        
	cnt_drop++;
        
        for(int i = 0; i<20; i++){
                volume += analogRead(MIC);
               delay(2); 
        }
        
	Serial.print(cnt_drop);
	Serial.print(" ");
	Serial.println(volume);
}

