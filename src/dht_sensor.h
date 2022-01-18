#ifndef DHT_SENSOR
#define DHT_SENSOR
#include <Arduino.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <string.h>
#include "mqtt.h"

#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setupDHT();
void retrieveDHTData();

#endif