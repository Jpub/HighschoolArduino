#include <SoftwareSerial.h>

SoftwareSerial ZigBee(2, 3);
int data1, data2, temp, seq = 0;

void setup(){
	Serial.begin(9600);
	ZigBee.begin(9600);
}

void loop(){
	if(ZigBee.available()) {
		data1 = ZigBee.parseInt();
		data2 = ZigBee.parseInt();

		if(data1 > data2) {
			int temp = data2;
			data2 = data1;
			data1 = temp;
		}
		if(data1 != 0 && data2 != 0) {
			Serial.print(seq);
			Serial.print(",");
			Serial.print(data1);
			Serial.print(",");
			Serial.println(data2 % 20000);
		}
		seq++;
	}
}
