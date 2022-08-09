#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial espSerial(10, 11);

void setup(){
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  espSerial.begin(9600);  
}

void loop(){
  if(espSerial.available() > 0) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(espSerial);
    String data = espSerial.readString();
    Serial.println("Data from firebase: " + data);

    if(!root.success()) {
      Serial.println("Parsing failed");
      jsonBuffer.clear();
    } else {
      Serial.print("Parsed from ESP: ");
      int buttonState = int(root["buttonState"]);
      Serial.println(buttonState);
      digitalWrite(13, buttonState);
      jsonBuffer.clear();
    }
  }  
}
