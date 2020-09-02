#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  unsigned int randNum, hiByte, loByte;
  
  for (int i = 0; i < 10; i += 2) {
    randNum = random(65536);
    Serial.print("Random : ");
    Serial.println(randNum);
    hiByte = highByte(randNum);
    loByte = lowByte(randNum);
    EEPROM.write(i, hiByte);
    EEPROM.write(i + 1, loByte);
  }
  
 Serial.println("");
 
  for (int i = 0; i < 10; i++) {
    Serial.print("ADDR = ");
    Serial.print(i);
    Serial.print(" Value = ");
    Serial.println(EEPROM.read(i));
  }
  
  Serial.println("");
  
  for (int i = 0; i < 10; i += 2) {
    hiByte = EEPROM.read(i);
    loByte = EEPROM.read(i + 1);
    Serial.print("Value : ");
    Serial.println(word(hiByte, loByte));
  }
}

void loop() {

}
