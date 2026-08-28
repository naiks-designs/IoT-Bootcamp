#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "MQ GAS"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define GAS_PIN 7

void setup()
{
  Serial.begin(115200);
  pinMode(GAS_PIN, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  int gasValue = digitalRead(GAS_PIN);

  if (gasValue == LOW)
  {
    Serial.println("Gas Detected");
    Blynk.virtualWrite(V0, 1);
  }
  else
  {
    Serial.println("No Gas");
    Blynk.virtualWrite(V0, 0);
  }

  delay(1000);
}