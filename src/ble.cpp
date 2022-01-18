#include "ble.h"
#include "action.h"

BLEServer* pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool bleDeviceConnected = false;
bool receivedBLEValue = false;
String inputBLEValue = "";

void ServerCallbacks::onConnect(BLEServer* pServer) {
  bleDeviceConnected = true;
  BLEDevice::startAdvertising();
  Serial.println("[BLE] Device connected");
};

void ServerCallbacks::onDisconnect(BLEServer* pServer) {
  bleDeviceConnected = false;
  Serial.println("[BLE] Device disconnected");
};

void CharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic) {
  std::string rxValue = pCharacteristic->getValue();
  if (rxValue.length() > 0) {
    inputBLEValue = "";
    for (int i = 0; i < rxValue.length(); i++) {
      inputBLEValue += (char)rxValue[i];
    }
    inputBLEValue.trim();
    inputBLEValue.toUpperCase();
    Serial.print("[BLE] Receive value: ");
    Serial.println(inputBLEValue);
    receivedBLEValue = true;
  }
};

void setupBLE() {
  // Create BLE Device
  BLEDevice::init("ESP32");

  // Create BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  // Create BLE Service
  BLEService* pService = pServer->createService(SERVICE_UUID);

  // Create BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ   |
    BLECharacteristic::PROPERTY_WRITE  |
    BLECharacteristic::PROPERTY_NOTIFY
  );

  // Create BLE Descriptor
  pCharacteristic->addDescriptor(new BLE2902());
  pCharacteristic->setCallbacks(new CharacteristicCallbacks());

  // Start BLE Service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("[BLE] Waiting a client connection to notify");
}

void bleLoop() {
  if (receivedBLEValue) {
    doAction(inputBLEValue.c_str());
    receivedBLEValue = false;
    inputBLEValue = "";
  }
}
