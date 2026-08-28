#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "PIR"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define PIR_PIN 7

void setup()
{
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  int pirValue = digitalRead(PIR_PIN);

  if (pirValue == HIGH)
  {
    Serial.println("MOTION DETECTED");
    Blynk.virtualWrite(V0, 1);
  }
  else
  {
    Serial.println("NO MOTION");
    Blynk.virtualWrite(V0, 0);
  }

  delay(500);
}