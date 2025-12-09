#define GAS_A A0
#define GAS_D 8
#define FIEZO 12
#define LED 13

void setup() {
  pinMode(FIEZO, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("히터 가열");
  delay(1000);
}

void loop() {
  digitalWrite(FIEZO, LOW);
  digitalWrite(LED, LOW);

  float sensorAvalue = analogRead(GAS_A);
  float sensorDvalue = digitalRead(GAS_D);

  Serial.print("아날로그 센서 입력: ");
  Serial.print(sensorAvalue);
  
  if(sensorAvalue > 300) {
    Serial.print(" !!연기 감지!! ");

    digitalWrite(FIEZO, HIGH);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(FIEZO, LOW);
    digitalWrite(LED, LOW);
  }

  Serial.print("디지털 센서 입력: ");
  Serial.println(sensorDvalue);

  delay(1000);
}