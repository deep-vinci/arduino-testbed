// // Declare variables here so both setup() and loop() can see them
int pin1 = 11; 
int pin2 = 49;

void setup() { 
  pinMode(11, OUTPUT); 
  pinMode(49, OUTPUT); 
} 

void loop() { 
  // LED 1 on, LED 2 off 
  digitalWrite(11, HIGH); 
  digitalWrite(49, LOW); 
  delay(400); 
  
  // LED 2 on, LED 1 off 
  digitalWrite(11, LOW); 
  digitalWrite(49, HIGH); 
  delay(400); 
}
