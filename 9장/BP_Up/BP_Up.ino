#include <OneWire.h>

int DS18S20_Pin = 2;

OneWire ds(DS18S20_Pin);

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  float temperature = getTemp();
  Serial.println(temperature);

  delay(1000); 
}

float getTemp()
{
  byte data[12];
  byte addr[8];

  if ( !ds.search(addr))
  {
    ds.reset_search();
    return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7])
  {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28)
  {
    Serial.print("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);


  for (int i = 0; i < 9; i++)
  {
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB);
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;
}

