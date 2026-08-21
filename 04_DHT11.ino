// DHT11 Temperature and Humidity
#include <DHT.h>

#define dht 7
#define DHTTYPE DHT11

DHT mydht(dht, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  mydht.begin();
}

void loop()
{
  float humidity = mydht.readHumidity();
  float temp = mydht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}
