#define SOIL_PIN 7

void setup()
{
  Serial.begin(115200);
  pinMode(SOIL_PIN, INPUT);
}

void loop()
{
  int soilValue = digitalRead(SOIL_PIN);

  if (soilValue == LOW)
  {
    Serial.println("SOIL IS WET");
  }
  else
  {
    Serial.println("SOIL IS DRY");
  }

  delay(1000);
}