#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "IR SENSOR"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define IR_PIN 7
#define LED_PIN 13

void setup()
{
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  int irValue = digitalRead(IR_PIN);

  if (irValue == LOW)
  {
    Serial.println("Object is detected");
    Blynk.virtualWrite(V0, 1);
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    Serial.println("Object is not detected");
    Blynk.virtualWrite(V0, 0);
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}