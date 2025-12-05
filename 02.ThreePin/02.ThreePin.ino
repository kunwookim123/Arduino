int Blue_Pin = 10;
int Green_Pin = 11;
int Red_Pin = 12;

void setup() {
  pinMode(Red_Pin, OUTPUT);
  pinMode(Green_Pin, OUTPUT);
  pinMode(Blue_Pin, OUTPUT);
}

void loop() {
  // LED켜기
  digitalWrite(Red_Pin, HIGH);
  delay(500);
  // LED끄기
  digitalWrite(Red_Pin, LOW);
  delay(500);

  digitalWrite(Green_Pin, HIGH);
  delay(500);
  digitalWrite(Green_Pin, LOW);
  delay(500);

  digitalWrite(Blue_Pin, HIGH);
  delay(500);
  digitalWrite(Blue_Pin, LOW);
  delay(500);
}
