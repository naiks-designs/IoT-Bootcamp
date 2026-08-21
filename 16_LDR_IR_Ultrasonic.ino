// LDR + IR + Ultrasonic
int ldr = A0;
int ir = 8;

int trig = 9;
int echo = 10;

void setup()
{
  pinMode(ir, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop()
{
  int ldrValue = analogRead(ldr);
  int irValue = digitalRead(ir);

  long duration;
  float distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("LDR: ");
  Serial.println(ldrValue);

  if (irValue == LOW)
    Serial.println("IR: Object Detected");
  else
    Serial.println("IR: No Object");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println();

  delay(500);
}
