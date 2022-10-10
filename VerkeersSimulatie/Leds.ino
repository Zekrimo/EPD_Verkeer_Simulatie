//led arrays voor stopzichten noord en zuid + de array size
int LICHTEN_NOORD[] = {7, 6, 5};
int LICHTEN_ZUID[] = {2, 3, 4};
const int LICHTEN_SIZE = 3;

//software timer varialbe voor waarschuwings lichten
unsigned long previousMillis_waarschuwingsLicht = 0;

// setup functie voor de leds
void setupLed() {
  for (int i = 0; i < LICHTEN_SIZE; i++) {
    pinMode(LICHTEN_NOORD[i], OUTPUT);
    pinMode(LICHTEN_ZUID[i], OUTPUT);
  }
}

////functies
//zet alleen rode led aan bij stoplicht, arry moet worden ingevoegd
void stoplichtRood(int array[]) {
  digitalWrite(array[0], HIGH);
  digitalWrite(array[1], LOW);
  digitalWrite(array[2], LOW);
}

void stoplichtGeel(int array[]) {
  digitalWrite(array[0], LOW);
  digitalWrite(array[1], HIGH);
  digitalWrite(array[2], LOW);
}

void stoplichtGroen(int array[]) {
  digitalWrite(array[0], LOW);
  digitalWrite(array[1], LOW);
  digitalWrite(array[2], HIGH);
}
//zet alleen rode led aan bij stoplicht noord
void noordStoplichtRood() {
  stoplichtRood(LICHTEN_NOORD);
}

//zet alleen rode led aan bij stoplicht zuid
void zuidStoplichtRood() {
  stoplichtRood(LICHTEN_ZUID);
}

//zet alleen rode led aan bij stoplicht
void alleStoplichtenRood() {
  stoplichtRood(LICHTEN_NOORD);
  stoplichtRood(LICHTEN_ZUID);
}



//licht controls voor noord lichten


void noordLichtenGeel() {
  stoplichtGeel(LICHTEN_NOORD);
}

void noordLichtenGroen() {
  stoplichtGroen(LICHTEN_NOORD);
}

//licht controls voor zuid lichten

void zuidLichtenGeel() {
  stoplichtGeel(LICHTEN_ZUID);
}

void zuidLichtenGroen() {
  stoplichtGroen(LICHTEN_ZUID);
}


void waarschuwingsLicht(int interval) {
  if (millis() - previousMillis_waarschuwingsLicht < interval ) {
    zuidLichtenGeel();
    noordLichtenGeel();
  } else if (millis() - previousMillis_waarschuwingsLicht < interval * 2) {
    digitalWrite(LICHTEN_ZUID[1], LOW);
    digitalWrite(LICHTEN_NOORD[1], LOW);
  } else {
    previousMillis_waarschuwingsLicht = millis();

  }
}
