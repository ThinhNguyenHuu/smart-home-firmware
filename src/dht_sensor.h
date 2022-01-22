#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Arduino.h>
#include "DHT.h"
#include <ArduinoJson.h>
#include "mqtt.h"

#define DHT_PIN 4
#define DHT_TYPE DHT11

void setupDHT();
void sendDHTData();

#endif


