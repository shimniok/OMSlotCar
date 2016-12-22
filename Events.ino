uint8_t events = 0;

void eventSet(uint8_t e) {
  events |= e;
}

void eventClr(uint8_t e) {
  events &= ~e;
}

boolean getEvent(uint8_t e) {
  boolean result = false;
  if (events & e) {
    result = true;
    eventClr(e);
  }
  return result;
}


