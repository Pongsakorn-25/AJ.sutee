#include <Wire.h>
#define _addr 0b0100000 

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(_addr);
  Wire.write(0x00);
  Wire.endTransmission();
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int _ledaddr = 1;
  int buff =analogRead(A0);
  int leds =map(buff,0,1023,1,8);
  int _pwm =map(buff,0,1023,0,255);
  analogWrite(10,_pwm);
  for(int i=1;i<leds;i++){
    _ledaddr =  _ledaddr<<1;
    _ledaddr =  _ledaddr|1; 
  }
  Wire.beginTransmission(_addr);
  Wire.write(_ledaddr);
  Wire.endTransmission();
}
