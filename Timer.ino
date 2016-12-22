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
    lap[i] = 0;
  }
  timer.start();
}

void timerTick() {
  elapsed++;
  if (elapsed > 99999)
    elapsed = 0;
}

void timerLap(uint8_t lane) {
  uint16_t delta;
  if (lane < LANES) {
    
    delta = elapsed - lastlaptime[lane];
    if (delta > 10) { // debounce -- 1 second lap time
      lap[lane]++;
      laptime[lane] = delta;
      lastlaptime[lane] = elapsed;
      updateLeader();
    }
  }
}

// Determine who is the current leader
// The leader, after passing the car detect,
// will always have the higher lap count
inline void updateLeader() {
  if (lap[0] > lap[1]) {
    leader = 0;
  } else if (lap[0] < lap[1]) {
    leader = 1;
  }
}

void timerStop() {
  timer.stop();
}



