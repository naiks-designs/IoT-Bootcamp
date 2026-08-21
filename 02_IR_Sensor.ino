// IR Sensor - Object Detection
int ir = 8;
int led = 2;

void setup()
{
  pinMode(ir, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int val = digitalRead(ir);

  if (val == LOW)
  {
    digitalWrite(led, HIGH);
    Serial.println("Object Detected");
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("No Object");
  }

  delay(500);
}
