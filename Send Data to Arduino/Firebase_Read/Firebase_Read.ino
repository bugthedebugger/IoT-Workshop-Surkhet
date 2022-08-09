#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "firebase database host"
#define FIREBASE_AUTH "firebase database password"
#define WIFI_SSID "wifi name"
#define WIFI_PASSWORD "wifi password"

void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi, please wait");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to WiFi with iP: "); 
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.stream("/buttonState");
}

void loop() {
  if(Firebase.failed()) {
    Serial.print("Streaming error: ");
    Serial.println(Firebase.error());
  }

  if(Firebase.available()) {
    FirebaseObject event = Firebase.readEvent();
    StaticJsonBuffer<256> jb;
    JsonObject& obj = jb.createObject();
    obj["buttonState"] = event.getBool("data");
    obj.printTo(Serial);
    jb.clear();
    Serial.flush();
    Serial.println();
  }
}
