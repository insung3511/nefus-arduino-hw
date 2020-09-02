#include <Servo.h>

Servo servo;

int servoPin = 3;
int val = 0;

void setup() {
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();
    if (input == '1') {
      if (val >= 170) {
        val = 0;
      } val += 30;
      Serial.print("Angle : ");
      Serial.println(val);
      servo.write(val);
    }
  }
}
