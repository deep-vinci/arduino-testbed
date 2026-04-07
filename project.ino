void setup() {
  pinMode(12, OUTPUT);  // Set pin 13 as output
}

void loop() {
  digitalWrite(12, HIGH);  // Turn LED on
  delay(1000);             // Wait 1 second
  digitalWrite(12, LOW);   // Turn LED off
  delay(1000);             // Wait 1 second
}