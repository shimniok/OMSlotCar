#include <serLCD.h>

serLCD lcd(LCDPIN);

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

void displayStart() {
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Press START");
  lcd.setCursor(2, 1);
  lcd.print("to begin race");
}

void displayReady() {
  lcd.clear(); 
  lcd.setCursor(1, 1);
  lcd.print("Wait for GREEN");
}

void displayGo() {
  lcd.clearLine(1);
  lcd.selectLine(1);
  lcd.print("  *** GO ***");  
}

void displayUpdate() {
  displayLaps();
  displayLeader();
  displayTimes();
}

inline void displayLeader() {
  if (leader == 0) {
    lcd.setCursor(1, 1);
    lcd.printCustomChar(1);
    lcd.setCursor(1, 9);
    lcd.print(' ');
  } else if (leader == 1) {
    lcd.setCursor(1, 1);
    lcd.print(' ');
    lcd.setCursor(1, 9);
    lcd.printCustomChar(1);
  } 
}

inline void displayLaps() {
  if (lap[0] == 1 || lap[1] == 1) {
    lcd.clear();
  }
  lcd.setCursor(1, 2);
  sprintf(buf, "%2d", lap[0]);
  lcd.print(buf);
  lcd.setCursor(1, 10);
  sprintf(buf, "%2d", lap[1]);
  lcd.print(buf);
}


inline void displayTimes() {

  cvTenthsToBuf(laptime[0]);
  lcd.setCursor(2, 2);
  lcd.print(buf);

  cvTenthsToBuf(laptime[1]);
  lcd.setCursor(2, 10);
  lcd.print(buf);
}


void cvTenthsToBuf(uint16_t t) {
  uint8_t minutes;
  uint8_t seconds;
  uint8_t tenths;

  tenths = t;
  seconds = t / 10;
  tenths -= seconds * 10;
  minutes = seconds / 60;
  seconds -= minutes * 60;
  sprintf(buf, "%02d:%02d.%01d", minutes, seconds, tenths);
}


