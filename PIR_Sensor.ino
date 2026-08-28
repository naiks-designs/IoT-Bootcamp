#define PIR_PIN 7

void setup()
{
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
}

void loop()
{
  int pirValue = digitalRead(PIR_PIN);

  if (pirValue == HIGH)
  {
    Serial.println("MOTION DETECTED");
  }
  else
  {
    Serial.println("NO MOTION");
  }

  delay(500);
}