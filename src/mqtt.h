#ifndef MQTT_H
#define MQTT_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <string.h>

void setupMQTT(MQTT_CALLBACK_SIGNATURE);
void connectToMQTTBroker();
void mqttLoop();

#endif