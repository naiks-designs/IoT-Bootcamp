#include <ESP32Servo.h>

Servo myServo;

#define SERVO_PIN 9

void setup()
{
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);
}

void loop()
{
  myServo.write(0);
  Serial.println("Servo = 0 degrees");
  delay(1000);

  myServo.write(90);
  Serial.println("Servo = 90 degrees");
  delay(1000);

  myServo.write(180);
  Serial.println("Servo = 180 degrees");
  delay(1000);
}