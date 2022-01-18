#include "action.h"

std::vector<Action*> actions;

Action* createAction(uint8_t pin, const char* key, Operation operation, uint8_t data) {
  Action* action = new Action();
  action->pin = pin;
  action->key = key;
  action->operation = operation;
  action->data = data;
  return action;
}

void setupActions() {
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  actions.push_back(createAction(RELAY_1_PIN, "LIGHT_1_ON", OPE_DIGITAL, HIGH));
  actions.push_back(createAction(RELAY_1_PIN, "LIGHT_1_OFF", OPE_DIGITAL, LOW));
  actions.push_back(createAction(RELAY_2_PIN, "LIGHT_2_ON", OPE_DIGITAL, HIGH));
  actions.push_back(createAction(RELAY_2_PIN, "LIGHT_2_OFF", OPE_DIGITAL, LOW));
}

Action* findActionByKey(const char* key) {
  for (uint8_t i = 0; i < actions.size(); ++i) {
    if (strcmp(actions[i]->key, key) == 0) {
      return actions[i];
    }
  }
  return NULL;
}

void doAction(const char* key) {
  Action* action = findActionByKey(key);
  if (action == NULL) {
    return;
  }

  if (action->operation == OPE_DIGITAL) {
    digitalWrite(action->pin, action->data);
  }
}

void doAction(const char* key, const uint8_t data) {
  Action* action = findActionByKey(key);
  if (action == NULL) {
    return;
  }

  if (action->operation == OPE_DIGITAL) {
    digitalWrite(action->pin, data);
  }
}
