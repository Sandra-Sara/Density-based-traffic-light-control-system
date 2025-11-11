#define IR_SENSOR_PIN 4

#define RED_LED 25
#define YELLOW_LED 26
#define GREEN_LED 27

void setup() {
  Serial.begin(115200);

  pinMode(IR_SENSOR_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.println("IR Sensor + Traffic Light LED Test Started");
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  if (sensorValue == LOW) { 
    // Obstacle detected
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    Serial.println("🚫 Obstacle Detected!");
  } else {
    // No obstacle
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("✅ Path Clear");
  }

  delay(300);
}
