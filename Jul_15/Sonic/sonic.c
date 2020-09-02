#define sigPin 8

void setup() {
  pinMode(sigPin, INPUT);
  pinMode(sigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(sigPin, LOW);
  unsigned long duration = pulseIn(sigPin, HIGH);
  float distance = duration / 29.0 / 2.0;
  
  Serial.print("Distance : ");
  Serial.println(distance);
}
