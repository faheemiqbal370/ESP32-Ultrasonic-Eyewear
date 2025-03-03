const int trigPin = 5;      // Trigger pin of ultrasonic sensor connected to GPIO 5
const int echoPin = 18;     // Echo pin connected to GPIO 18
const int buzzerPin = 4;    // Buzzer connected to GPIO 4

const int distanceThreshold = 25;

void setup() {
  Serial.begin(115200);           
  pinMode(trigPin, OUTPUT);     
  pinMode(echoPin, INPUT);       
  pinMode(buzzerPin, OUTPUT);    
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < distanceThreshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(100); 
}
