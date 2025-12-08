#define TRIG 9
#define ECHO 8 
#define PIEZO 12
#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(PIEZO, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(PIEZO, LOW);
  digitalWrite(LED, LOW);

  digitalWrite(TRIG,HIGH);
  delay(10);
  digitalWrite(TRIG,LOW);

  float duration = pulseIn(ECHO,HIGH);
  float distance = ((34000*duration)/1000000)/2;
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  if (distance < 100){
    Serial.println("PIEZO - LED");
    digitalWrite(PIEZO, HIGH);
    digitalWrite(LED, HIGH);
  }
  delay(100); 
}