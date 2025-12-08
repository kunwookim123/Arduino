#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(c) || isnan(f)) {
    Serial.println("측정 실패");
    return;
  }

  Serial.println("습도: " + String(h) + "% | 섭씨 온도: " + String(c) +
    "°C | 화씨 온도: " + String(f) + "°F");
}
