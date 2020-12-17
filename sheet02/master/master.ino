void setup() {
  // initialize serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
  
  Serial.println("Send 'o' or 'O' to ON  Led");
  Serial.println("Send 'f' or 'F' to OFF Led");
}
void loop() {
  if (Serial.available()) {
    char inChar = Serial.read();
    if (inChar == ('o')||inChar == ('O')) {     
      Serial.print(inChar);
      Serial1.print(inChar);
    }
    if (inChar == ('f')||inChar == ('F')) {
     Serial.print(inChar);
     Serial1.print(inChar);
    }
  }
}
