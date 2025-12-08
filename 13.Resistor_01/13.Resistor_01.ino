void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop() {
  int readValue = analogRead(A0);
  Serial.println(readValue);
  // map()이라는 내장함수를 이용해 입력값을 최소,최대값을 설정하고 그에 따른 출력값을 매핑하여 변환해주는 것
  // map(매개변수, 입력값의 최소값, 입력값의 최대값, 출력값의 최소값, 출력값의 최대값)
  readValue = map(readValue, 0, 1023, 0, 255);
  analogWrite(6, readValue);
  delay(100);
}
