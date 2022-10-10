//buttons pins
const int BUTTONS[] = {A3, A4, A5};
const int BUTTONS_SIZE = 3;

////variable voor wachtrij
const int LEEGEWAARDE = 42;
int wachtrij[] {LEEGEWAARDE, LEEGEWAARDE, LEEGEWAARDE};
const int WACHTRIJ_SIZE = 3;

//variable voor wachtrij verzoek
const int VERZOEK_NOORD = 0;
const int VERZOEK_OVERSTEKEN = 1;
const int VERZOEK_ZUID = 2;


//setup voor de buttons
void setupButtons() {
  for ( int button = 0; button < BUTTONS_SIZE; button++) {
    pinMode(BUTTONS[button], INPUT);
  }
}

////functies
//check of de button is ingedrukt
void checkButton() {
  for (int i = 0; i < BUTTONS_SIZE; i++) {
    if (digitalRead(BUTTONS[i]) == HIGH) {
      VoegToeAanWachtrij(i);
    }
  }
}

// voegt toe aan aan wachtrij indien het niet al in de wachtrij staat
void VoegToeAanWachtrij(int waarde) {
  if (alInWachtrij(waarde) == false) {
    for ( int i = 0; i < WACHTRIJ_SIZE; i++) {
      if (wachtrij[i] == LEEGEWAARDE) {
        wachtrij[i] = waarde;
        return;
      }
    }
  } else {
    //debug om te kijken of verzoek al in wachtrij staat
    Serial.println("al in wachtrij");
  }
}

//check of verzoek al in wachtrij staat
boolean alInWachtrij(int waarde) {
  for ( int i = 0; i < WACHTRIJ_SIZE; i++) {
    if (wachtrij[i] == waarde) {
      return true;
    }
  }
  return false;
}

// getter voor eerstvolgende in wachtrij
int getEersteInWachtrij() {
  return wachtrij[0];
}

//functie die wachtrij met 1 posititie verschuift
void verschuifWachtrij() {
  Serial.println("ik ga schuiven");
  for (int i = 1; i < WACHTRIJ_SIZE; i++) {
    wachtrij[i - 1] = wachtrij[i];
  }
  wachtrij[WACHTRIJ_SIZE - 1] = LEEGEWAARDE;
}

// debug functie voor het tonen van de wachtrij
void showWachtrij() {
  for (int i = 0; i < WACHTRIJ_SIZE; i++) {
    Serial.print(wachtrij[i]);
  }
  Serial.println(" ");
}
