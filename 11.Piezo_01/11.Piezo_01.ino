const int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523
}
const int PIEZO_PIN = 8;

void setup() {
  tone(PIEZO_PIN, melody[0], 500); delay(500);
  tone(PIEZO_PIN, melody[1], 500); delay(500);
  tone(PIEZO_PIN, melody[2], 500); delay(500);
  tone(PIEZO_PIN, melody[3], 500); delay(500);
  tone(PIEZO_PIN, melody[4], 500); delay(500);
  tone(PIEZO_PIN, melody[5], 500); delay(500);
  tone(PIEZO_PIN, melody[6], 500); delay(500);
  tone(PIEZO_PIN, melody[7], 500); delay(500);
}

void loop() {
}
