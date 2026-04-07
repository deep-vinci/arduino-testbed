void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // LED 1 on, LED 2 off
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(250);

  // LED 2 on, LED 1 off
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(250);
}