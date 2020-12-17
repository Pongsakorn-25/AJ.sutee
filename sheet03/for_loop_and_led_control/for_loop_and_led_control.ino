void setup() {
  // put your setup code here, to run once:
    for(int i = 2;i<10;i++){
      pinMode(i,OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int i=2;i<10;i++){
      digitalWrite(i,HIGH);
      delay(500);
      digitalWrite(i,LOW);
    }
    delay(100);
    for(int i=9;i>1;i--){
      digitalWrite(i,HIGH);
      delay(1000);
      digitalWrite(i,LOW);
    }
    delay(100);
    for(int i=0;i<4;i++){
      digitalWrite(5-i,HIGH);
      digitalWrite(6+i,HIGH);
      delay(1000);
      digitalWrite(5-i,LOW);
      digitalWrite(6+i,LOW);
    }
    delay(100);
}
