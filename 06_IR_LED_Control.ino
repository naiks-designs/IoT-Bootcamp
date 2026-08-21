// IR Sensor with LED Control
int ir = 8;
int led = 2;

void setup()
{
  pinMode(ir, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int val = digitalRead(ir);

  if (val == LOW)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
