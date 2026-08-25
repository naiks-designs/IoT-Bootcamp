#include <WiFi.h>

// Wi-Fi credentials
const char* ssid = "AirFiber-Uqu3AM";
const char* password = "12346360";

// GPIO pins
#define LED 13
#define RELAY 36
#define BUZZER 35

// Web server
WiFiServer server(80);

void setup() {

  Serial.begin(115200);

  // Set pins as OUTPUT
  pinMode(LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Initially OFF
  digitalWrite(LED, LOW);
  digitalWrite(RELAY, LOW);
  digitalWrite(BUZZER, LOW);

  // Connect to Wi-Fi
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  // Display IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.begin();

  Serial.println("Web Server Started!");
}

void loop() {

  // Check for client
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  // Read browser request
  String request = client.readStringUntil('\r');

  // Clear client buffer
  client.flush();

  // =========================
  // LED CONTROL
  // =========================

  if (request.indexOf("/led/on") != -1) {
    digitalWrite(LED, HIGH);
    Serial.println("LED ON");
  }

  if (request.indexOf("/led/off") != -1) {
    digitalWrite(LED, LOW);
    Serial.println("LED OFF");
  }

  // =========================
  // RELAY CONTROL
  // =========================

  if (request.indexOf("/relay/on") != -1) {
    digitalWrite(RELAY, HIGH);
    Serial.println("RELAY ON");
  }

  if (request.indexOf("/relay/off") != -1) {
    digitalWrite(RELAY, LOW);
    Serial.println("RELAY OFF");
  }

  // =========================
  // BUZZER CONTROL
  // =========================

  if (request.indexOf("/buzzer/on") != -1) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("BUZZER ON");
  }

  if (request.indexOf("/buzzer/off") != -1) {
    digitalWrite(BUZZER, LOW);
    Serial.println("BUZZER OFF");
  }

  // =========================
  // HTTP RESPONSE
  // =========================

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  // =========================
  // WEBPAGE
  // =========================

  client.println("<!DOCTYPE html>");
  client.println("<html>");

  client.println("<head>");

  client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");

  client.println("<title>ESP32 IoT Control</title>");

  client.println("<style>");

  client.println("body {");
  client.println("font-family: Arial, sans-serif;");
  client.println("text-align: left;");
  client.println("margin: 30px;");
  client.println("background-color: #f2f2f2;");
  client.println("}");

  client.println("h1 {");
  client.println("margin-bottom: 30px;");
  client.println("}");

  client.println(".control {");
  client.println("margin-bottom: 25px;");
  client.println("}");

  client.println("h2 {");
  client.println("margin-bottom: 10px;");
  client.println("}");

  client.println("button {");
  client.println("padding: 12px 25px;");
  client.println("margin-right: 10px;");
  client.println("font-size: 18px;");
  client.println("cursor: pointer;");
  client.println("}");

  client.println("</style>");

  client.println("</head>");

  client.println("<body>");

  client.println("<h1>ESP32 IoT Control</h1>");

  // =========================
  // LED
  // =========================

  client.println("<div class='control'>");

  client.println("<h2>LED</h2>");

  client.println("<a href='/led/on'>");
  client.println("<button>LED ON</button>");
  client.println("</a>");

  client.println("<a href='/led/off'>");
  client.println("<button>LED OFF</button>");
  client.println("</a>");

  client.println("</div>");

  // =========================
  // RELAY
  // =========================

  client.println("<div class='control'>");

  client.println("<h2>RELAY</h2>");

  client.println("<a href='/relay/on'>");
  client.println("<button>RELAY ON</button>");
  client.println("</a>");

  client.println("<a href='/relay/off'>");
  client.println("<button>RELAY OFF</button>");
  client.println("</a>");

  client.println("</div>");

  // =========================
  // BUZZER
  // =========================

  client.println("<div class='control'>");

  client.println("<h2>BUZZER</h2>");

  client.println("<a href='/buzzer/on'>");
  client.println("<button>BUZZER ON</button>");
  client.println("</a>");

  client.println("<a href='/buzzer/off'>");
  client.println("<button>BUZZER OFF</button>");
  client.println("</a>");

  client.println("</div>");

  client.println("</body>");
  client.println("</html>");

  // Close connection
  client.stop();

  Serial.println("Client Disconnected");
}