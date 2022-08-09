# IoT Workshop Surkhet Examples

This project will hold two examples:

1. Sending data to Arduino from Firebase

2. Sending data from Arduino to Firebase

Required library versions:

```txt
ESP8266 Module Version: 2.7.x
ArduinoJSON Version: 5.13.5
```

## Uploading to Arduino/ESP8266

In order for these examples to work, we will require the following steps:

1. Ensure Arduino is in reset mode by either uploading a blank sketch or by connecting reset to GND

2. Connect RX, TX of ESP8266 to Arduino's RX, TX and GP00 of ESP8266 needs to be connected to GND

3. Select ESP8266 from board menu

4. Upload the WiFi related to code to ESP8266 first

5. Disconnect RX, TX, GP00 of ESP8266

6. Select Arduino from board menu

7. Upload Arduino related code to Arduino

8. Since we are utilizing software serial to communicate between Arduino and ESP8266, connect Rx of ESP8266 to software Tx of Arduino, connect Tx of ESP8266 to software Rx of Arduino

### Schematics for Uploading to ESP8266

![alt Programming ESP8266](Schematics/Programming%20ESP8266_bb.png)

### Schematics for Uploading to Arduino and communicate data between Arduino-ESP8266

![alt Programming ESP8266](Schematics/Reading-Writing%20From%20ESP%20to%20Arduino_bb.png)
