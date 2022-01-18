#include "mqtt.h"

const char* mqtt_server = "broker.hivemq.com";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setupMQTT(MQTT_CALLBACK_SIGNATURE) {
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback);
}

void connectToMQTTBroker() {
  while (!mqttClient.connected()) {
    Serial.println("[MQTT] Attempt to connect");
    String clientId = "ESP32";

    if (mqttClient.connect(clientId.c_str())) {
      Serial.println("[MQTT] connected");
      mqttClient.subscribe("testtopic/1");
      mqttClient.subscribe("testtopic/2");
    } else {
      Serial.print("[MQTT] Failed, rc = ");
      Serial.print(mqttClient.state());
      Serial.println("[MQTT] Try again in 5 seconds");
      delay(5000);
    }
  }
}

void mqttLoop() {
  if (!mqttClient.connected()) {
    connectToMQTTBroker();
  }
  mqttClient.loop();
}