#define rPin 5;

void setup() {
  pinMode(rPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int rVal = analogRead(rPin);
  Serial.print("Sensor : ");
  Serial.println(rVal);
}
