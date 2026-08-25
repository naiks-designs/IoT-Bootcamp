# ESP32 Web Server – LED, Buzzer and Relay Control

A simple ESP32 Wi-Fi web server project that allows an LED, buzzer, and relay to be controlled from a web browser.

## Project Overview

The ESP32 connects to a Wi-Fi network and creates a web server on port 80. After connecting, the ESP32 prints its IP address in the Serial Monitor.

The user can open that IP address in a web browser and control:

- LED – ON / OFF
- Buzzer – ON / OFF
- Relay – ON / OFF

## Components

- ESP32
- LED
- Buzzer
- Relay Module
- Jumper wires
- Wi-Fi network

## Pin Connections

| Component | ESP32 Pin |
|---|---|
| LED | GPIO 13 |
| Buzzer | GPIO 35 |
| Relay | GPIO 36 |

## How It Works

1. The ESP32 connects to the configured Wi-Fi network.
2. A web server is started on port 80.
3. The ESP32 IP address is displayed in the Serial Monitor.
4. The IP address is entered into a web browser connected to the same network.
5. The web page displays ON and OFF buttons for the LED, buzzer, and relay.
6. When a button is pressed, the browser sends a request to the ESP32.
7. The ESP32 reads the request and changes the corresponding output.

## Web Control URLs

| Device | ON | OFF |
|---|---|---|
| LED | `/led/on` | `/led/off` |
| Buzzer | `/buzzer/on` | `/buzzer/off` |
| Relay | `/relay/on` | `/relay/off` |

## Arduino Code

```cpp
#include <WiFi.h>

const char* ssid = "AirFiber-Uqu3AM";
const char* password = "12346360";

#define LED 13
#define BUZZER 35
#define RELAY 36

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(RELAY, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/led/on") != -1) {
    digitalWrite(LED, HIGH);
  }

  if (request.indexOf("/led/off") != -1) {
    digitalWrite(LED, LOW);
  }

  if (request.indexOf("/buzzer/on") != -1) {
    digitalWrite(BUZZER, HIGH);
  }

  if (request.indexOf("/buzzer/off") != -1) {
    digitalWrite(BUZZER, LOW);
  }

  if (request.indexOf("/relay/on") != -1) {
    digitalWrite(RELAY, HIGH);
  }

  if (request.indexOf("/relay/off") != -1) {
    digitalWrite(RELAY, LOW);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  client.println("<html>");
  client.println("<head>");
  client.println("<title>ESP32 Control</title>");
  client.println("</head>");

  client.println("<body>");
  client.println("<h1>ESP32 Control</h1>");

  client.println("<h2>LED</h2>");
  client.println("<a href='/led/on'><button>ON</button></a>");
  client.println("<a href='/led/off'><button>OFF</button></a>");

  client.println("<h2>Buzzer</h2>");
  client.println("<a href='/buzzer/on'><button>ON</button></a>");
  client.println("<a href='/buzzer/off'><button>OFF</button></a>");

  client.println("<h2>Relay</h2>");
  client.println("<a href='/relay/on'><button>ON</button></a>");
  client.println("<a href='/relay/off'><button>OFF</button></a>");

  client.println("</body>");
  client.println("</html>");

  client.stop();
}
```

## Setup

1. Open the code in Arduino IDE.
2. Select the correct ESP32 board and COM port.
3. Enter your Wi-Fi credentials in the code.
4. Upload the program to the ESP32.
5. Open the Serial Monitor at **115200 baud**.
6. Wait for `WiFi Connected`.
7. Copy the IP address displayed by the ESP32.
8. Open the IP address in a browser connected to the same Wi-Fi network.
9. Use the buttons to control the LED, buzzer, and relay.

## Notes

- The ESP32 and control devices should have a suitable common ground.
- Use an appropriate power supply for the relay and connected load.
- Check the exact ESP32 board pinout before using GPIO 35 and GPIO 36 as outputs.
- Do not connect mains voltage directly to ESP32 GPIO pins.

## Project Result

The ESP32 works as a Wi-Fi web server and provides browser-based control of an LED, buzzer, and relay.

## License

This project is intended for learning and educational purposes.
