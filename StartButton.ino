#include <PinChangeInt.h>

void startInit() {
  attachPinChangeInterrupt(BUTTON, handleStart, RISING);
}

void handleStart() {
  eventSet(EVENT_BUTTON);
}

void waitForStartButton() {
  while (getEvent(EVENT_BUTTON));
}

boolean startPressed() {
  return (getEvent(EVENT_BUTTON)); 
}

