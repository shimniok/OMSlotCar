#include <serLCD.h>
#include <SoftwareSerial.h>
#include "Events.h"

#define LANES 2

serLCD lcd(7);

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
}

void loop() {

  displayUpdate();

  // ready to start race
  // waiting for start button
  //start.waitForPress();
  startSequence();

  while (1) {
    if (getEvent(EVENT_LAP)) {
      displayUpdate();
    }
    delay(10);
  }
  
  // wait for 2nd start line break
  // display time behind

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


