
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
  delay(3000);
  displayInit();
  timerInit();
  detectInit();
  startInit();
}

void loop() {

  displayUpdate();
  waitForStartButton();
  startSequence();

  while (1) {

    if (startPressed()) break;
    
    if (getEvent(EVENT_LAP)) {
      displayUpdate();
    }
    delay(10);
  }
  
  // wait for next car to pass
  // display intermediate time
  // increment lap count

}

void startSequence() {
  for (int i=5; i >= 0; i--) {
    delay(500);
    startLight(i);
    if (i == 0) timerStart();
  }
}


