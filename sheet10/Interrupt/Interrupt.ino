const byte SW = 2;

int freq = 2500;
int SW_state;
int led= 3;
void setup() {
 pinMode(SW, INPUT);
 pinMode(led,OUTPUT);
 attachInterrupt(digitalPinToInterrupt(SW),toggle, LOW);
}
void loop() {
 tone(7, freq, 1000);
 delay(1000);
}
void toggle() {
  digitalWrite(led,!digitalRead(led));
}
