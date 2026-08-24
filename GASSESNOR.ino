int buzzer =35;
int gas_dig = 4;
int gas_anal = A0;

int val;
int analog_val;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(gas_dig, INPUT);
  pinMode(gas_anal, INPUT);
  Serial.begin(9600);
}

void loop() {

  val = digitalRead(gas_dig);
  analog_val = analogRead(gas_anal);

  Serial.print("Analog Value: ");
  Serial.println(analog_val);

  if (val == LOW) {
    digitalWrite(buzzer, HIGH);
    Serial.println("Gas Detected!");
  }
  else {
    digitalWrite(buzzer, LOW);
    Serial.println("No Gas");
  }

  delay(1000);
}