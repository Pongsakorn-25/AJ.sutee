#include <Servo.h>
Servo myservo;

int val;
int SW1 = 3;
int SW2 = 4;
int SW3 = 5;
void setup() {
  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  pinMode(SW3,INPUT);
 myservo.attach(2);
}
void loop() {
 if(digitalRead(SW1)==0){
  delay(10);
  while(digitalRead(SW1)==0);
  delay(10);
  myservo.write(90);
 }
 if(digitalRead(SW2)==0){
   delay(10);
  while(digitalRead(SW1)==0);
  delay(10);
  myservo.write(90);
 }
 if(digitalRead(SW3)==0){
   delay(10);
  while(digitalRead(SW1)==0);
  delay(10);
  myservo.write(90);
 }
 
}
