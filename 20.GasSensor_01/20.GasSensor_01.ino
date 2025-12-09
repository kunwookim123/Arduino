#define GAS_A A0
#define GAS_D 8

void setup() {
  Serial.begin(9600);
  Serial.println("히터가열");
  delay(1000);
}

void loop() {
  float sensorAvalue = analogRead(GAS_A);
  float sensorDvalue = digitalRead(GAS_D);

  Serial.print("아날로그 센서 입력: ");
  Serial.print(sensorAvalue);

  if(sensorAvalue > 300) {
    Serial.print(" |연기감지!");
    Serial.println("");
  }

  Serial.print("디지털 센서 입력: ");
  Serial.print(sensorDvalue);
  Serial.println("");

  delay(1000);
}
