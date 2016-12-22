volatile uint8_t eventflags = 0;

void eventSet(uint8_t e) {
  eventflags |= (1<<e);
}

void eventClr(uint8_t e) {
  eventflags &= ~(1<<e);
}

boolean getEvent(uint8_t e) {
  boolean result;

  if ((eventflags & (1<<e)) == 0) {
    result = false;
  } else {
    result = true;
    eventClr(e);
  }
  
  return result;
}


