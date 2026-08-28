#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "LDR"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define LDR_PIN 4
#define LED_PIN 13

void setup()
{
  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  int ldrValue = digitalRead(LDR_PIN);

  Serial.print("LDR: ");
  Serial.println(ldrValue);

  Blynk.virtualWrite(V0, ldrValue);

  if (ldrValue == LOW)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Dark - LED ON");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Light - LED OFF");
  }

  delay(1000);
}