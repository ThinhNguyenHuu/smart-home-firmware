#ifndef ACTION_H
#define ACTION_H

#include <Arduino.h>
#include <vector>

#define RELAY_1_PIN 18
#define RELAY_2_PIN 19

enum Operation { OPE_DIGITAL, OPE_ANALOG };

struct Action {
  uint8_t pin;
  const char* key;
  Operation operation;
  uint8_t data;
};

Action* createAction(uint8_t pin, const char* key, Operation operation, uint8_t data);

void setupActions();

Action* findActionByKey(const char* key);
void doAction(const char* key);
void doAction(const char* key, const uint8_t data);

#endif