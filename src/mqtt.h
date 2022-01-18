#ifndef MQTT_H
#define MQTT_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <string.h>

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

void setupMQTT();
void connectToMQTTBroker();
void mqttLoop();
void mqttCallback(char* topic, byte* payload, unsigned int length);

#endif