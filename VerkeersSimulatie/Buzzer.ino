//buzzer pin
const int BUZZER = 8;

//software timer
unsigned long currentMillisBuzzer;
unsigned long previousMillisLinksBuzzer = 0;


//setup voor buzzer
void setupBuzzer() {
  pinMode(BUZZER, OUTPUT);
}

//functie om buzzer af te laten gaan met meegegeven interval
void buzzerBeep(int interval) {
  currentMillisBuzzer = millis();
  if (currentMillisBuzzer - previousMillisLinksBuzzer >= interval) {
    tone(BUZZER, 500, 100);
    if (currentMillisBuzzer - previousMillisLinksBuzzer >= interval * 2) {
      noTone(BUZZER);
      previousMillisLinksBuzzer = currentMillisBuzzer;
    }
  }
}
