const int PANEL_PIN = A0;
const int SW_PIN = 2;

// 가상 에너지 저장소
long energy = 0;

// 판매 단위
const long SELL_UNIT = 100; // 설정한 단위만큼 판매

// 충전 스케일 조정 (밝을수록 더 빨리 charging)
const int MAX_CHARGE_RATE = 50; // 전압이 5V일 때 설정한 값 만큼 적립
void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
  // 1. 태양광 패널 전압 읽기 (0~5V)
  int raw = analogRead(PANEL_PIN);
  float voltage = (raw * 5.0) / 1023.0;

  // 2. 전압기반 충전 공식
  // gain = 전압 비율 * 최대 충전량
  int gain = (voltage / 5.0) * MAX_CHARGE_RATE;

  if (gain > 0) {
    energy += gain;
  }

  // 3. 버튼 눌림 감지
  bool prev = HIGH;
  bool curr = digitalRead(SW_PIN);
  
  if (prev == HIGH && curr == LOW) {
    Serial.println("판매 요청");

    if (energy > SELL_UNIT) {
      energy -= SELL_UNIT;
      Serial.print("판매 성공! | 판매량: ");
      Serial.print(SELL_UNIT);
      Serial.print("| 남은 에너지양: ");
      Serial.println(energy);
    } else {
      Serial.print("판매 실패 | 남은 에너지양이 부족합니다. | 현재 남은 양: ");
      Serial.println(energy);
    }
  }
  prev = curr;

  // 4. 현재 상태
  Serial.print("전압: ");
  Serial.print(voltage);
  Serial.print("v | 적립량: +");
  Serial.print(gain);
  Serial.print(" | 현재 에너지: ");
  Serial.println(energy);

  delay(1000);
}
