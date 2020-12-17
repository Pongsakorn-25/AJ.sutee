void setup() {
 pinMode(2,OUTPUT);
}
void loop() {
 int x = map(analogRead(A0),0,1023,0,255);
 analogWrite(2,x);
}
