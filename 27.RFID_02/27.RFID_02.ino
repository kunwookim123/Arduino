#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_R 2
#define LED_B 3
#define PIEZO 7

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();

  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  if(!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    delay(500);
    return;
  }

  if(mfrc.uid.uidByte[0] == 97 && mfrc.uid.uidByte[1] == 255 
    && mfrc.uid.uidByte[2] == 171 && mfrc.uid.uidByte[3] == 93) {
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_R, LOW);
    Serial.println("Verify!");
    digitalWrite(PIEZO, HIGH);
    delay(500);
    digitalWrite(PIEZO, LOW);
    digitalWrite(LED_B, LOW);
    } else {
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_B, LOW);
      Serial.println("Error!");
      digitalWrite(PIEZO, HIGH);
      delay(500);
      digitalWrite(PIEZO, LOW);
      delay(500);
      digitalWrite(PIEZO, HIGH);
      delay(500);
      digitalWrite(PIEZO, LOW);
      digitalWrite(LED_R, LOW);  
    }
}