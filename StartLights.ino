// Start Lights
// Expects 5 start led lights, charlieplexed to pins CHARLIE0, CHARLIE1, CHARLIE2

void charliePin(int p, int m, int v) {
  digitalWrite(p, v); 
  pinMode(p, m);
}

// Turns on the specified 5-light start led light
// 0 = off
// 1 = green
// 2 = red 1
// 3 - red 2
// 4 - red 3
// 5 - red 4
void startLight(int light) {
  switch (light) {
  case 0:  
    charliePin(CHARLIE0, INPUT, LOW);
    charliePin(CHARLIE1, INPUT, LOW);
    charliePin(CHARLIE2, INPUT, LOW);
    break;
  case 1:
    charliePin(CHARLIE0, OUTPUT, HIGH);
    charliePin(CHARLIE1, OUTPUT, LOW);
    charliePin(CHARLIE2, INPUT, LOW);
    break;
  case 2:
    charliePin(CHARLIE0, OUTPUT, LOW);
    charliePin(CHARLIE1, OUTPUT, HIGH);
    charliePin(CHARLIE2, INPUT, LOW);
    break;     
  case 3:
    charliePin(CHARLIE0, INPUT, LOW);
    charliePin(CHARLIE1, OUTPUT, HIGH);
    charliePin(CHARLIE2, OUTPUT, LOW);
    break;     
  case 4:
    charliePin(CHARLIE0, INPUT, LOW);
    charliePin(CHARLIE1, OUTPUT, LOW);
    charliePin(CHARLIE2, OUTPUT, HIGH);
    break; 
  case 5:
    charliePin(CHARLIE0, OUTPUT, HIGH);
    charliePin(CHARLIE1, INPUT, LOW);
    charliePin(CHARLIE2, OUTPUT, LOW);
    break;
  default:
    break;
  }
}



