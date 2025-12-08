void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  int resistor = analogRead(A0);
  Serial.println(resistor);

  if (resistor > 700)
  digitalWrite(7, HIGH);

  else
  digitalWrite(7, LOW);
}
