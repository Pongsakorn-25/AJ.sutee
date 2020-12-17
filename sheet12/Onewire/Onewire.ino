#include <OneWire.h>
OneWire ds(10); // on pin 10 (a 4.7K resistor is necessary)
float room_temp = 25; 
void setup(void) {
 Serial.begin(9600);
}
float RD_TEMP(void){
   byte i;
 byte present = 0;
 byte data[12];
 byte addr[8];
 float celsius, fahrenheit;
 if ( !ds.search(addr)) {
 Serial.println("No more addresses.");
 Serial.println();
 ds.reset_search();
 delay(250);
 return;
 }
 Serial.println();
 ds.reset();
 ds.select(addr);
 ds.write(0x44, 1); // start conversion
 delay(1000);
 present = ds.reset();
 ds.select(addr);
 ds.write(0xBE); // Read Scratchpad
 for ( i = 0; i < 9; i++) {
 data[i] = ds.read();
 }
 int16_t raw = (data[1] << 8) | data[0];
 byte cfg = (data[4] & 0x60);
 if (cfg == 0x00) raw = raw & ~7;
 else if (cfg == 0x20) raw = raw & ~3;
 else if (cfg == 0x40) raw = raw & ~1;
 celsius = (float)raw / 16.0;
 Serial.print(" Temperature = ");
 Serial.print(celsius);
 Serial.print(" Celsius");
 return celsius ;
}
void loop(void) {
 float buff =RD_TEMP()-room_temp;
 if(buff<5){
  return;
 }
 
 if(buff>15){
 tone(7, 2500, 1000);
 delay(4000);
  return;
 }
 if(buff<10){
  tone(7, 2500, 1000);
 delay(2000);
  return;
 }
 if(buff<5){
  tone(7, 2500, 1000);
 delay(1000);
  return;
 }
}
