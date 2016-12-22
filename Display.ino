byte arrow[8] = {
  0b00000,
  0b10000,
  0b11000,
  0b11100,
  0b11110,
  0b11100,
  0b11000,
  0b10000
};

char buf[20];

void displayInit() {
  lcd.createChar(1, arrow);
  delay(10);
  lcd.clear(); 
}

void displayUpdate() {
  displayLaps();
  displayLeader();
  displayTimes();
}

inline void displayLeader() {
  if (leader == 0) {
    lcd.setCursor(1, 1);
  } else if (leader == 1) {
    lcd.setCursor(1, 9);
  } 
  if (leader < LANES) {
    lcd.printCustomChar(1);
  }
}

inline void displayLaps() {
  lcd.setCursor(1, 2);
  sprintf(buf, "%2d", lap[0]);
  lcd.print(buf);
  lcd.setCursor(1, 10);
  sprintf(buf, "%2d", lap[1]);
  lcd.print(buf);
}


inline void displayTimes() {
  lcd.selectLine(2);
  lcd.setCursor(2, 2);

  cvTenthsToBuf(elapsed);
  lcd.print(buf);
  lcd.setCursor(2, 10);
  lcd.print(buf);
}


void cvTenthsToBuf(uint16_t t) {
  uint8_t minutes;
  uint8_t seconds;
  uint8_t tenths;

  tenths = elapsed;
  seconds = elapsed / 10;
  tenths -= seconds * 10;
  minutes = seconds / 60;
  seconds -= minutes * 60;
  sprintf(buf, "%02d:%02d.%01d", minutes, seconds, tenths);
}


