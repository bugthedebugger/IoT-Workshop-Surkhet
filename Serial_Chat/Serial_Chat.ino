#include <SoftwareSerial.h>

SoftwareSerial arduinoSerial(10, 11);


void setup() {
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  arduinoSerial.begin(9600);
}

void loop() {
  if(arduinoSerial.available()) {
    Serial.print("Arduino buddy says: ");
    Serial.print(arduinoSerial.readString());
  }

  if(Serial.available()) {
      String message = Serial.readString();
      arduinoSerial.print(message);
      Serial.print("You said: ");
      Serial.print(message);
  }
}
