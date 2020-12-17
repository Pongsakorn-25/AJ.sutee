int IN[] = {2, 3, 4, 5};
const int del = 2500;
int mode=0;
bool _dir=0;
int SW1 = 6;
int SW2 = 7;
int SW3 = 8;
void setup()
{
 for (int i=0;i<4;i++){
 pinMode(IN[i], OUTPUT);
 }
 pinMode(SW1,INPUT);
 pinMode(SW2,INPUT);
 pinMode(SW3,INPUT);
}

void loop()
{
  if(digitalRead(SW1)==0){
    delay(10);
    while(digitalRead(SW3)==0);
    delay(10);
    if(mode == 1){
      step_wave(_dir,8);
    }
     if(mode == 2){
      if(_dir==0){
        full_wave_cc();
        full_wave_cc();
      }else{
        full_wave_cw();
        full_wave_cw();
      }
    }
     if(mode == 3){
       if(_dir==0){
        half_step_cc();
        half_step_cc();
      }else{
        half_step_cw();
        half_step_cw();
      }
    }
  }
  if(digitalRead(SW2)==0){
    delay(10);
    while(digitalRead(SW3)==0);
    delay(10);
    _dir!=_dir;
  } 
  if(digitalRead(SW3)==0){
    delay(10);
    while(digitalRead(SW3)==0);
    delay(10);
    mode++;
    if(mode>2){
      mode = 0;
    }
  }
}
void step_wave(int dir,int _step){
if(dir =0){
  for(int i = 0;i<_step;i++){
    digitalWrite(IN[i%4], HIGH);
    delayMicroseconds(3333);
    digitalWrite(IN[i%4], LOW);
  }
}
if(dir =1){
  for(int i = _step;i>0;i--){
    digitalWrite(IN[i%4], HIGH);
    delayMicroseconds(3333);
    digitalWrite(IN[i%4], LOW);
  }
}
}
void full_wave_cc (){//45degree
   digitalWrite(IN[3], LOW);
   digitalWrite(IN[0], HIGH);
   digitalWrite(IN[1], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[0], LOW);
   digitalWrite(IN[1], HIGH);
   digitalWrite(IN[2], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[1], LOW);
   digitalWrite(IN[2], HIGH);
   digitalWrite(IN[3], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[2], LOW);
   digitalWrite(IN[3], HIGH);
   digitalWrite(IN[0], HIGH);
   delayMicroseconds(3333);
}
void full_wave_cw (){//45degree
   digitalWrite(IN[2], LOW);
   digitalWrite(IN[1], LOW);
   digitalWrite(IN[0], HIGH);
   digitalWrite(IN[3], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[0], LOW);
   digitalWrite(IN[3], HIGH);
   digitalWrite(IN[2], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[3], LOW);
   digitalWrite(IN[2], HIGH);
   digitalWrite(IN[1], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[2], LOW);
   digitalWrite(IN[1], HIGH);
   digitalWrite(IN[0], HIGH);
   delayMicroseconds(3333);
}
void half_step_cc(){//45degree
   digitalWrite(IN[3], LOW);//step1
   digitalWrite(IN[0], HIGH);//step1
   delayMicroseconds(3333);
   digitalWrite(IN[0], HIGH);//step2
   digitalWrite(IN[1], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[0], LOW);//step3
   digitalWrite(IN[1], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[1], HIGH);//step4
   digitalWrite(IN[2], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[1], LOW);//step5
   digitalWrite(IN[2], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[2], HIGH);//step6
   digitalWrite(IN[3], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[2], LOW);//step7
   digitalWrite(IN[3], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[3], HIGH);//step8
   digitalWrite(IN[0], HIGH);
   delayMicroseconds(3333);
}

void half_step_cw(){//45degree
   digitalWrite(IN[0], HIGH);//step8
   digitalWrite(IN[3], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[0], LOW);//step7
   digitalWrite(IN[3], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[3], HIGH);//step6
   digitalWrite(IN[2], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[3], LOW);//step5
   digitalWrite(IN[2], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[2], HIGH);//step4
   digitalWrite(IN[1], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[2], LOW);//step3
   digitalWrite(IN[1], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[1], HIGH);//step2
   digitalWrite(IN[0], HIGH);
   delayMicroseconds(3333);
   digitalWrite(IN[1], LOW);//step1
   digitalWrite(IN[0], HIGH);
   delayMicroseconds(3333);
}
