void setup() {
  // initialize serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}
void loop() {
  if (Serial1.available()) {
    char inChar = Serial1.read();
    if (inChar == ('o')||inChar == ('O')) {     
      Serial.print(inChar);
      digitalWrite(LED_BUILTIN,HIGH);
    }
    if (inChar == ('f')||inChar == ('F')) {
     Serial.print(inChar);
     digitalWrite(LED_BUILTIN,HIGH);
    }
  }
}
