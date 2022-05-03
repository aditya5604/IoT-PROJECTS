#define LED 2

void setup() {
  // Set pin mode
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(500);
  digitalWrite(LED,HIGH);
  Serial.println("LIGHT ON");
  delay(500);
  digitalWrite(LED,LOW);
  Serial.println("LIGHT OFF");
}
