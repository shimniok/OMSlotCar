#include <EnableInterrupt.h>
#include "Pins.h"
#include "Events.h"

#define LANES 2

uint8_t laptotal=3;
uint8_t leader=99;
uint16_t elapsed; // in tenths of a second
uint16_t laptime[LANES]; // in tenths of a second
uint16_t lastlaptime[LANES]; // in tenths of a second
uint8_t lap[LANES];

void setup() {
  delay(200);
  displayInit();
  timerInit();
  startInit();
  detectDisable();
}

void loop() {

  displayStart();
  delay(200);
  waitForStartButton();

  // Enter # of laps
  
  displayReady();  
  delay(3000);

  startLights();
  detectEnable();

  while (1) {
    delay(50);
    if (startPressed()) break;
    
    if (getEvent(EVENT_LAP)) {
      if (lap[leader] >= laptotal) {
        displayWinner();
        beepWinner();
        delay(2000);
        break;
      } else {
        displayUpdate();
        beep();
      }
    }
  }

  timerStop();

}

void startLights() {
  for (int i=5; i > 0; i--) {
    delay(1000);
    startLight(i);
    beepLo();
  }
  timerStart(); // start timer when green lights
  beepHi();
  displayGo();
  delay(1000);
  startLight(0); // all lights off
}


