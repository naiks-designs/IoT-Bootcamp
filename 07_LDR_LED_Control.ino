// LDR with LED Control
int ldr = A0;
int led = 2;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(ldr);

  Serial.println(value);

  if (value < 500)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }

  delay(200);
}
