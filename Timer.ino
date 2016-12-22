#include <TimerOne.h>

TimerOne timer;

void timerInit() {
  timer.initialize(100000UL);
  timer.attachInterrupt(timerTick);
}

void timerStart() {
  elapsed = 0;
  for (int i=0; i < LANES; i++) {
    laptime[i] = 0;
  }
  timer.start();
}

void timerTick() {
  elapsed++;
  if (elapsed > 99999)
    elapsed = 0;
}

void timerLap(uint8_t lane) {
  if (lane < LANES) {
    lap[lane]++;
    laptime[lane] = elapsed - lastlaptime[lane];
    lastlaptime[lane] = elapsed;
    updateLeader();
  }
}

inline void updateLeadre() {
}

void timerStop() {
  timer.stop();
}



