#include <serLCD.h>
#include <SoftwareSerial.h>

#define LANES 2

serLCD lcd(7);

uint16_t elapsed; // in tenths of a second
uint16_t laptime[LANES]; // in tenths of a second
uint16_t lastlaptime[LANES]; // in tenths of a second
uint8_t lap[LANES];

void setup() {
  delay(3000);
  displayInit();
  timerInit();
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  detectInit();
}

void loop() {

  displayLaps();
  displayTimes();

  // ready to start race
  // waiting for start button
  //start.waitForPress();
  startSequence();

  while (1) {
    displayLaps();
    displayTimes();
    delay(200);
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


