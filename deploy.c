
#define TRIG_FRONT 7
#define ECHO_FRONT 8

#define TRIG_UPPER 4
#define ECHO_UPPER 5

#define WATER_SENSOR A0
#define BUZZER_PIN 10
#define MOTOR_PIN 11

#define WATER_THRESHOLD 300

long duration;
int frontDistance;
int upperDistance;
int waterValue;

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    return 999;
  }

  return duration * 0.0343 / 2;
}

void setup() {
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);

  pinMode(TRIG_UPPER, OUTPUT);
  pinMode(ECHO_UPPER, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  Serial.begin(9600);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(MOTOR_PIN, LOW);

  Serial.println("ADVANCED SMART BLIND STICK");
}

void loop() {

  // Read both ultrasonic sensors one after another
  frontDistance = getDistance(TRIG_FRONT, ECHO_FRONT);
  delay(50);

  upperDistance = getDistance(TRIG_UPPER, ECHO_UPPER);
  delay(50);

  // Read water sensor
  waterValue = analogRead(WATER_SENSOR);

  Serial.print("Front Distance: ");
  Serial.print(frontDistance);
  Serial.println(" cm");

  Serial.print("Upper Distance: ");
  Serial.print(upperDistance);
  Serial.println(" cm");

  Serial.print("Water Value: ");
  Serial.println(waterValue);

  // Water alert has highest priority
  if (waterValue > WATER_THRESHOLD) {
    tone(BUZZER_PIN, 2000);
    digitalWrite(MOTOR_PIN, HIGH);
    Serial.println("WATER DETECTED!");
    delay(150);
    return;
  }

  // Find the nearest detected obstacle
  int nearestDistance = min(frontDistance, upperDistance);

  // Very close obstacle
  if (nearestDistance <= 10) {
    tone(BUZZER_PIN, 2000);
    digitalWrite(MOTOR_PIN, HIGH);
    Serial.println("DANGER: VERY CLOSE!");
  }

  // Obstacle within 20 cm
  else if (nearestDistance <= 20) {
    digitalWrite(MOTOR_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    delay(100);
    noTone(BUZZER_PIN);
    delay(150);
  }

  // Obstacle within 40 cm
  else if (nearestDistance <= 40) {
    digitalWrite(MOTOR_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    delay(100);
    noTone(BUZZER_PIN);
    delay(600);
  }

  // No nearby obstacle
  else {
    noTone(BUZZER_PIN);
    digitalWrite(MOTOR_PIN, LOW);
    delay(50);
  }
}
