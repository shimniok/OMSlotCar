
void detectEnable() {
  enableInterrupt(2, handleCar0, RISING);
  enableInterrupt(3, handleCar1, RISING);
}

void detectDisable() {
  disableInterrupt(2);
  disableInterrupt(3);
}

void handleCar0() {
  timerLap(0);
  eventSet(EVENT_LAP);
}

void handleCar1() {
  timerLap(1);
  eventSet(EVENT_LAP);
}

