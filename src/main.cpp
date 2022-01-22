#include <Arduino.h>
#include <string.h>
#include "arduino_wifi.h"
#include "mqtt.h"
#include "ble.h"
#include "action.h"
#include "dht_sensor.h"

void setup() {  
  Serial.begin(115200);
  while (!Serial) {}

  setupWiFi();
  setupMQTT();
  setupBLE();
  setupActions();
  setupDHT();
}

void loop() {
  mqttLoop();
  bleLoop();
  sendDHTData();
}