uint8_t events;

#define EVENT_LAP     (1<<0)
#define EVENT_BUTTON  (1<<1)

void eventSet(uint8_t e) {
  events |= e;
}

void eventClr(uint8_t e) {
  events &= ~e;
}

uint8_t isEventSet(uint8_t e) {
  return events & e;
}


