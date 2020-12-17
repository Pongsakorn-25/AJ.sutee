#include <SPI.h>
int latchpin = 48;
int datapin = 51;
int clockpin = 52;
int prev_t = 0;
int SW1 = 2;
int SW2 = 3;
int SW3 = 4;
char number[]= {0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09,0xFF};
char digit[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
char disp_c[4];
int count;
bool enable_c=false;
void setup() {
 SPI.begin();
 SPI.setBitOrder(LSBFIRST);
 pinMode(latchpin, OUTPUT);
 pinMode(datapin, OUTPUT);
 pinMode(clockpin, OUTPUT);
 delay(500);
}
void loop() {
 if(digitalRead(SW1)==0){
   disp_c[0]=10;
   disp_c[1]=10;
   disp_c[2]=10;
   disp_c[3]=10;
   enable_c = true;
 }
 
 if((digitalRead(SW2)==0)&&enable_c){
  count = 0;
  long pp1;
   while(1){
    disp_c[0] = count%10;
    disp_c[1] = (count/10)%10;
    disp_c[2] = (count/100)%10; 
    disp_c[3] = (count/1000)%10; 

  for(char j=0;j<4;j++){
   digitalWrite(latchpin, LOW);
   SPI.transfer(number[disp_c[j]]);
   SPI.transfer(digit[j]);
   digitalWrite(latchpin, HIGH);
   delay(2);
  }
  if(millis()-pp1>500){
    count++;
    pp1 = millis();;
  }
  if(count>=100){
    enable_c = false;
    return;
  }
 }
 }
 
 if((digitalRead(SW3)==0)&&enable_c){
  count = 99;
  long pp2;
   while(1){
    disp_c[0] = count%10;
    disp_c[1] = (count/10)%10;
    disp_c[2] = (count/100)%10; 
    disp_c[3] = (count/1000)%10; 

  for(char j=0;j<4;j++){
   digitalWrite(latchpin, LOW);
   SPI.transfer(number[disp_c[j]]);
   SPI.transfer(digit[j]);
   digitalWrite(latchpin, HIGH);
   delay(2);
  }
  if(millis()-pp2>500){
    count--;
    pp2 = millis();;
  }
  if(count<=0){
    enable_c =false;
    return;
  }
 }
}

 for(char j=0;j<4;j++){
   digitalWrite(latchpin, LOW);
   SPI.transfer(number[disp_c[j]]);
   SPI.transfer(digit[j]);
   digitalWrite(latchpin, HIGH);
   delay(2);
}

} 
