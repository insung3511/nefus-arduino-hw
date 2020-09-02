int echoPin = 8;
int trigPin = 9;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(12,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
    digitalWrite(12, LOW);
  digitalWrite(echoPin, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 29.0 /2.0;
  Serial.print("Distance : ");
  Serial.println(distance);
  
  if (distance <= 120) {
    digitalWrite(12, HIGH);
  }
}
