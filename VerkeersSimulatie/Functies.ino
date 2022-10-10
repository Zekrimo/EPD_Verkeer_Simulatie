//timer waardes voor countDown functie
unsigned long currentMillisCountDown;
int intervalCountDown = 1000;
unsigned long previousMillisCountDown = 0 - intervalCountDown;

//timer waardes voor delay functie
unsigned long previousMillisDelay;
unsigned long currentMillisDelay = millis();

//teller voor counDown functie
int digitCountDown = 6;

// boolean die true is indien de countdown klaar is
boolean isCountDownKlaar = false;



//functies
void countDown() {
  clearShiftRegister;
  currentMillisCountDown = millis();
  if (isCountDownKlaar == false) {
    if (currentMillisCountDown - previousMillisCountDown <= intervalCountDown) {
      showDigit(CIJFERS[digitCountDown]);
    } else {
      clearShiftRegister();
      digitCountDown--;
      previousMillisCountDown = currentMillisCountDown;
      if (digitCountDown < 0) {
        clearShiftRegister();
        digitCountDown = 6;
        isCountDownKlaar = true;
      }
    }
  }
}

//software delay timer
boolean delayTimer(int interval) {
  currentMillisDelay = millis();
  return (millis() > previousMillisDelay + interval);
}

// reset voor de software delay timer
void resetDelayTimer() {
  previousMillisDelay = millis();
}
