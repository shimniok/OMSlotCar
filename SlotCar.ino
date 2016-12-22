
#include <EnableInterrupt.h>
#include "Pins.h"
#include "Events.h"

#define LANES 2

uint8_t leader=99;
uint16_t elapsed; // in tenths of a second
uint16_t laptime[LANES]; // in tenths of a second
uint16_t lastlaptime[LANES]; // in tenths of a second
uint8_t lap[LANES];

void setup() {
  delay(2000);
  displayInit();
  timerInit();
  startInit();
  detectDisable();
}

void loop() {

  displayStart();
  delay(200);
  waitForStartButton();
  displayReady();  
  delay(3000);

  startLights();
  detectEnable();

  while (1) {
    delay(50);
    if (startPressed()) break;
    
    if (getEvent(EVENT_LAP)) {
      displayUpdate();
    }
  }

  timerStop();

}

void startLights() {
  for (int i=5; i > 0; i--) {
    delay(500);
    startLight(i);
  }
  timerStart(); // start timer when green lights
  displayGo();
  delay(500);
  startLight(0); // all lights off
}


