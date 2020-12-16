int LEDs[]={4,5,6,7};
int SW1 = 2;
int mode = 0;
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<4;i++){
  pinMode(LEDs[i],OUTPUT);
}
pinMode(SW1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(SW1)==0){
    delay(10);
    while(digitalRead(SW1)==0);
    delay(10);
    mode++;
    if(mode>4){
      mode = 0;
    }
 }
 for(int i = 1;i<5;i++){
    if(i==mode){
      digitalWrite(i-1,HIGH);
    }else{
      digitalWrite(i-1,LOW);
    }
 }
}
