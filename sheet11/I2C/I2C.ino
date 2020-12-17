#include <Wire.h>
#define _addr 0b0100000 

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(_addr);
  Wire.write(0x00);
  Wire.endTransmission();
}
void led_control(byte b){
  byte _ledaddr=1;
  if(b=0){
    return ;
  }else if(b=1){

    _ledaddr = 0x00;
  }else if(b=2){
    if( _ledaddr == 0x00){
      _ledaddr = 0x01;
    }else{
      _ledaddr<<1;
    }  
  }else if(b=3){
     if( _ledaddr == 0x00){
      _ledaddr = 0x04;
    }else{
      _ledaddr>>1;
    }
  }
  
  Wire.beginTransmission(_addr);
  Wire.write(_ledaddr);
  Wire.endTransmission();
  
}
byte SW_RD (void){
  byte dt;
  Wire.requestFrom(_addr,1);
  delay(50);
  if(Wire.available()){
    dt = Wire.read();
    dt = dt&0xF0;
    while(SW_RD() == dt);
    
  }
  switch(dt){
    case 0x40:
        return 1;
        break;
    case 0x20:
        return 2;
        break;
    case 0x10:
        return 3;
        break;
    default:
        return 0;
        break;
    }
  
 
}
void loop() {
  // put your main code here, to run repeatedly:
   led_control(SW_RD);
}
