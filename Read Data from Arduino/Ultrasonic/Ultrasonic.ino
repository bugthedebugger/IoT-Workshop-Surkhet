#include <SoftwareSerial.h>
#include <ArduinoJson.h>

const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor

SoftwareSerial espSerial(10, 11);

void setup() {
   pinMode(10, INPUT);
   pinMode(11, OUTPUT);
   Serial.begin(115200);
   espSerial.begin(9600);
}

void loop() {
   long duration, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.println("cm");

   StaticJsonBuffer<256> jb;
   JsonObject& obj = jb.createObject();
   obj["distanceInCm"] = cm;
   obj.printTo(espSerial);
   jb.clear();

   if(espSerial.available() > 0) {
      Serial.print("Data from ESP: ");
      Serial.println(espSerial.readString()); 
   }

   delay(2000);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
