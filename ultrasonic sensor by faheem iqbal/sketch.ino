// Define pins
const int trigPin = 5;      // Trigger pin of ultrasonic sensor connected to GPIO 5
const int echoPin = 18;     // Echo pin connected to GPIO 18
const int buzzerPin = 4;    // Buzzer connected to GPIO 4

// Define threshold distance in cm
const int distanceThreshold = 25;

void setup() {
  Serial.begin(115200);           // Start serial communication
  pinMode(trigPin, OUTPUT);       // Set trigger as output
  pinMode(echoPin, INPUT);        // Set echo as input
  pinMode(buzzerPin, OUTPUT);     // Set buzzer pin as output
}

void loop() {
  long duration;
  int distance;

  // Send a 10us HIGH pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If object is closer than threshold, turn on buzzer
  if (distance > 0 && distance < distanceThreshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);  // Small delay for stability
}
