#include <Arduino.h>
#include <string.h>
#include "arduino_wifi.h"
#include "mqtt.h"
#include "ble.h"
#include "action.h"

void processCommand(String cmd);

void setup() {  
  Serial.begin(115200);
  while (!Serial) {}

  setupWiFi();
  setupMQTT();
  setupBLE();
  setupActions();
}

void loop() {
  mqttLoop();
  bleLoop();
}

void processCommand(String command) {
}