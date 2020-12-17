#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int SW1 = 8;
int SW2 = 9;
int SW3 = 10;
int LED1 = 6;
int LED2 = 7;
void setup() {
 lcd.begin(16, 2);
 pinMode(LED1,OUTPUT);
 pinMode(LED2,OUTPUT);

 pinMode(SW1,INPUT);
 pinMode(SW2,INPUT);
 pinMode(SW3,INPUT);
}
void loop(){
  if(digitalRead(SW1)==0){
    delay(10);
    while(digitalRead(SW1)==0);
    delay(10);
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    lcd.setCursor(6,0);
    lcd.print("LED 1 ON");
  }
   if(digitalRead(SW2)==0){
    delay(10);
    while(digitalRead(SW2)==0);
    delay(10);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    lcd.setCursor(6,0);
    lcd.print("LED 2 ON");
  }
   if(digitalRead(SW3)==0){
    delay(10);
    while(digitalRead(SW3)==0);
    delay(10);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    lcd.setCursor(6,0);
    lcd.print("STOP");
  }
}
