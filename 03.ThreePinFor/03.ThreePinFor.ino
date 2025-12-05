// 배열 선언 방법
// [] - 대괄호 사용 => 배열을 선언하거나 접근할 때 사용

// 선언
int leds[] = {12,11,10}; // 중괄호를 사용해서 사용
int count = 3;

void setup() {
  for (int i = 0; i < count; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < count; i++) {
    digitalWrite(leds[i], HIGH);
    delay(500);
  }
  for (int i = 0; i < count; i++) {
    digitalWrite(leds[i], LOW);
    delay(500);
  }
}
