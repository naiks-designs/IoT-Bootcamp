#define RAIN_PIN 7

void setup()
{
  Serial.begin(115200);
  pinMode(RAIN_PIN, INPUT);
}

void loop()
{
  int rainValue = digitalRead(RAIN_PIN);

  if (rainValue == LOW)
  {
    Serial.println("RAIN DETECTED");
  }
  else
  {
    Serial.println("NO RAIN");
  }

  delay(1000);
}