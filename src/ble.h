#ifndef BLE_H
#define BLE_H
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>
#include <BLE2902.h>
#include <string.h>

#define SERVICE_UUID        "9c1c732b-42ff-4a4e-b534-377c36563cc4"
#define CHARACTERISTIC_UUID "c557048e-a081-4bc3-9fa0-7582474915d6"

class ServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer);
  void onDisconnect(BLEServer* pServer);
};

class CharacteristicCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic* pCharacteristic);
};

void setupBLE();
void bleLoop();

#endif