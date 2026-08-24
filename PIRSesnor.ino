int pir = 4;
int buzzer = 35;

void setup() {

  Serial.begin(9600);

  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, LOW);
}

void loop() {

  int value = digitalRead(pir);

  if (value == HIGH) {

    digitalWrite(buzzer, HIGH);
    Serial.println("MOTION DETECTED! - BUZZER ON");

  } 
  else {

    digitalWrite(buzzer, LOW);
    Serial.println("No Motion - BUZZER OFF");

  }

  delay(1000);
}