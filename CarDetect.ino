
void detectInit() {
  enableInterrupt(2, handleCar0, RISING);
  enableInterrupt(3, handleCar1, RISING);
}

void handleCar0() {
  timerLap(0);
  eventSet(EVENT_LAP);
}

void handleCar1() {
  timerLap(1);
  eventSet(EVENT_LAP);
}

