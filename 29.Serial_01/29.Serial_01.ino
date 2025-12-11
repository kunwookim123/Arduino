int data;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  while (Serial.available()) { // 시리얼 통신이 정상적으로 연결되었다면?
    // 시리얼 통신을 통해 수신된 것이 있는지 확인
    data = Serial.read();
  }

  // 시리얼 통신으로 전달받은 값이 1이라면 LED를 켜고, 0이라면 LED를 끈다
  if (data == '1') {
    digitalWrite(13, HIGH);
  } else if (data == '0') {
    digitalWrite(13, LOW);
  }
}
