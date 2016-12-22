
void detectInit() {
  attachInterrupt(digitalPinToInterrupt(CAR0PIN), handleCar0, RISING);
  attachInterrupt(digitalPinToInterrupt(CAR1PIN), handleCar1, RISING);
}

void handleCar0() {
  timerLap(0);
  eventSet(EVENT_LAP);
}

void handleCar1() {
  timerLap(1);
  eventSet(EVENT_LAP);
}

