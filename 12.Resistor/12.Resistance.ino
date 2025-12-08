void setup() {
  Serial.begin(9600);
}

void loop() {
  int readValue = analogRead(A0);
  delay(500);
  Serial.println(readValue);
}
