// Start Lights
// Expects 5 start led lights, charlieplexed to pins L1, L2, L3

#define L1 8
#define L2 9
#define L3 10

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
    charliePin(L1, INPUT, LOW);
    charliePin(L2, INPUT, LOW);
    charliePin(L3, INPUT, LOW);
    break;
  case 1:
    charliePin(L1, OUTPUT, HIGH);
    charliePin(L2, OUTPUT, LOW);
    charliePin(L3, INPUT, LOW);
    break;
  case 2:
    charliePin(L1, OUTPUT, LOW);
    charliePin(L2, OUTPUT, HIGH);
    charliePin(L3, INPUT, LOW);
    break;     
  case 3:
    charliePin(L1, INPUT, LOW);
    charliePin(L2, OUTPUT, HIGH);
    charliePin(L3, OUTPUT, LOW);
    break;     
  case 4:
    charliePin(L1, INPUT, LOW);
    charliePin(L2, OUTPUT, LOW);
    charliePin(L3, OUTPUT, HIGH);
    break; 
  case 5:
    charliePin(L1, OUTPUT, HIGH);
    charliePin(L2, INPUT, LOW);
    charliePin(L3, OUTPUT, LOW);
    break;
  default:
    break;
  }
}



