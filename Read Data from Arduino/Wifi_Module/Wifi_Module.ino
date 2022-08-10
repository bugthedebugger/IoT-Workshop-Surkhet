#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "<databasename>.firebaseio.com"
#define FIREBASE_AUTH "database password"
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
}

void loop() {
  if(Serial.available() > 0) {
    String dataFromSerial = Serial.readString();
    StaticJsonBuffer<256> jb;
    JsonObject& root = jb.parseObject(Serial);

    if(!root.success()) {
      jb.clear();  
    } else {
      float distanceInCM = float(root["distanceInCm"]);
      Firebase.setFloat("/sensors/ultrasonic", distanceInCM);

      if(Firebase.failed()) {
        Serial.print("Failed to write to /sensors/ultrasonic: ");
        Serial.println(Firebase.error());
      }
      jb.clear();
    }
  }
}
