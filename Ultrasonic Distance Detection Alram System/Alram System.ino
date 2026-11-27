#define TRIG_PIN 12
#define ECHO_PIN 13
#define BUZZER_PIN 9

const int ALARM_DISTANCE = 20;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("ULTRASONIC DISTANCE ALARM");
  Serial.println("System Started");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    noTone(BUZZER_PIN);
    Serial.println("No Object Detected");
    delay(500);
    return;
  }

  float distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= ALARM_DISTANCE) {
    Serial.println("WARNING! OBJECT NEAR");

    tone(BUZZER_PIN, 1000);
  } else {
    noTone(BUZZER_PIN);
    Serial.println("Object at Safe Distance");
  }

  delay(300);
}
