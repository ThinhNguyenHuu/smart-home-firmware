#include <Arduino.h>
#include <string.h>
#include "arduino_wifi.h"
#include "mqtt.h"
#include "ble.h"

void mqttCallback(char* topic, byte* payload, unsigned int length);
void processCommand(String cmd);

void setup() {  
  Serial.begin(115200);
  while (!Serial) {}

  setupWiFi();
  setupMQTT(mqttCallback);
  setupBLE();
}

void loop() {
  mqttLoop();
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("[MQTT] Message arrive [");
  Serial.print(topic);
  Serial.print("] ");
  String command = "";
  for (int i = 0; i < length; i++) {
    command += (char)payload[i];
  }
  command.trim();
  Serial.println(command);
  processCommand(command);
}

void processCommand(String command) {
}