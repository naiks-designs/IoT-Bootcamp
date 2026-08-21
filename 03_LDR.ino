// LDR - Analog Light Reading
int ldr = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(ldr);

  Serial.print("LDR Value: ");
  Serial.println(value);

  delay(500);
}
