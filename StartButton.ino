
void startInit() {
  pinMode(BUTTON, INPUT_PULLUP);
  enableInterrupt(BUTTON, handleStart, FALLING);
  pinMode(13, OUTPUT);
}

void waitForStartButton() {
  while (getEvent(EVENT_BUTTON) == 0) {
    delay(200);
    digitalWrite(13, digitalRead(13) ? LOW : HIGH);
  }
}

boolean startPressed() {
  return (getEvent(EVENT_BUTTON)); 
}

void handleStart() {
  eventSet(EVENT_BUTTON);
}

