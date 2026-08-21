// IR + DHT11 + Ultrasonic
#include <DHT.h>

#define dht 7
#define DHTTYPE DHT11

int ir = 8;
int trig = 9;
int echo = 10;

DHT mydht(dht, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  pinMode(ir, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  mydht.begin();
}

void loop()
{
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

  float humidity = mydht.readHumidity();
  float temp = mydht.readTemperature();

  if (irValue == LOW)
    Serial.println("IR: Object Detected");
  else
    Serial.println("IR: No Object");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("--------------------");

  delay(2000);
}
