#define IN3 4
#define IN4 3
#define ENB 2
#define DR_SW 33
#define CR_SW 32
#define STOP_SW 31
int mode = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(ENB, OUTPUT);
 pinMode(CR_SW, INPUT);
 pinMode(DR_SW, INPUT);
 pinMode(STOP_SW, INPUT);
 digitalWrite(IN3, !digitalRead(IN3));
 digitalWrite(IN4, !digitalRead(IN3));
 digitalWrite(ENB, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(CR_SW)==LOW){
 delay(10);
 while(digitalRead(CR_SW)==LOW);
 delay(10);
 mode++;
 if(mode>4){
  mode =1; 
 }
 int buf =map(mode*25,0,100,0,255);
 analogWrite(ENB,buf);
 }
  
if(digitalRead(STOP_SW)==LOW){
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 digitalWrite(ENB, LOW);
 mode =0; 
 }
 
 
 if(digitalRead(DR_SW)==LOW){
 delay(10);
 while(digitalRead(DR_SW)==LOW);
 delay(10);
 digitalWrite(IN3, !digitalRead(IN3));
 digitalWrite(IN4, !digitalRead(IN3));
 }
}
