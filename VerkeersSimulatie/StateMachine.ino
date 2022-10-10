//cases voor state machine
const int RIJDEN_NOORD = 1;
const int AFREMMEN_NOORD = 2;
const int RIJDEN_ZUID = 3;
const int AFREMMEN_ZUID = 4;
const int OVERSTEKEN = 5;
const int DODENTIJD  = 7;
const int OPENSLAGBOOM = 8;
const int SLUITSLAGBOOM = 9;
const int COUNTDOWN = 10;
const int OPENSLAGBOOM_NACHT = 11;
const int NACHTSTAND = 12;
const int SLUITSLAGBOOM_NACHT = 13;

//status voor state machine
int status;

//state machine
void loopStateMachine() {
  switch (status) {
    case RIJDEN_NOORD:
      do_rijden_noord();
      if (delayTimer(3000)) {
        exit_rijden_noord();
        status = AFREMMEN_NOORD;
        entry_afremmen_noord();
      }
      break;
    case AFREMMEN_NOORD:
      do_afremmen_noord();
      if (delayTimer(2000)) {
        exit_afremmen_noord();
        status = DODENTIJD;
        entry_dodentijd();
      }
      break;
    case RIJDEN_ZUID:
      do_rijden_noord();
      if (delayTimer(3000)) {
        exit_rijden_zuid();
        status = AFREMMEN_ZUID;
        entry_afremmen_zuid();
      }
      break;
    case AFREMMEN_ZUID:
      do_afremmen_zuid();
      if (delayTimer(2000)) {
        exit_afremmen_zuid();
        status = DODENTIJD;
        entry_dodentijd();
      }
      break;
    case OVERSTEKEN:
      do_oversteken();
      if (delayTimer(4000)) {
        exit_oversteken();
        status = COUNTDOWN;
        entry_countdown();
      }
      break;
    case DODENTIJD:
      do_dodentijd();

      if (delayTimer(2000)) {
        if (getEersteInWachtrij() == VERZOEK_NOORD) {

          exit_dodentijd();
          status = RIJDEN_NOORD;
          entry_rijden_noord();
        } else if (getEersteInWachtrij() == VERZOEK_OVERSTEKEN) {

          exit_dodentijd();
          status = OPENSLAGBOOM;
          entry_openslagboom();
        } else if (getEersteInWachtrij() == VERZOEK_ZUID) {


          exit_dodentijd();
          status = RIJDEN_ZUID;
          entry_rijden_zuid();
        } else if ( getMappedPotmeterValue(10) > 5) {
          exit_dodentijd();
          status = OPENSLAGBOOM_NACHT;
          entry_openslagboom_nacht();
        }
      }
      break;
    case OPENSLAGBOOM:
      do_openslagboom();
      if (servoPositie > SLAGBOOM_OPEN - 1) {
        exit_openslagboom();
        status = OVERSTEKEN;
        entry_oversteken();
      }
      break;
    case SLUITSLAGBOOM:
      do_sluitslagboom();
      if (servoPositie < SLAGBOOM_DICHT + 1) {
        exit_sluitslagboom();
        status = DODENTIJD;
        entry_dodentijd();
      }
      break;
    case COUNTDOWN:
      do_countdown();
      if (isCountDownKlaar) {
        exit_countdown();
        status = SLUITSLAGBOOM;
        entry_sluitslagboom();
      }
      break;
    case OPENSLAGBOOM_NACHT:
      do_openslagboom_nacht();
      if (servoPositie > SLAGBOOM_OPEN - 1) {
        exit_openslagboom_nacht();
        status = NACHTSTAND;
        entry_nachtstand();
      }
      break;
    case NACHTSTAND:
      do_nachtstand();
      if (getMappedPotmeterValue(10) < 5) {
        exit_nachtstand();
        status = SLUITSLAGBOOM;
        entry_sluitslagboom_nacht();
      }
      break;
    case SLUITSLAGBOOM_NACHT:
      do_sluitslagboom_nacht();
      if (servoPositie < SLAGBOOM_DICHT + 1) {
        exit_sluitslagboom_nacht();
        status = SLUITSLAGBOOM;
        entry_dodentijd();
      }
      break;
    default:
      // statements
      break;
  }
}

//setup state machine

void setupStateMachine() {

  entry_dodentijd();
  status = DODENTIJD;
}

////// do, entry, exits

////RIJDEN_NOORD

//entry

void entry_rijden_noord() {

  noordLichtenGroen();
  resetDelayTimer();
}

//do

void do_rijden_noord() {

}

//exit

void exit_rijden_noord() {

}

////AFREMMEN_NOORD

///entry

void entry_afremmen_noord() {
  noordLichtenGeel();
  resetDelayTimer();
}

//do

void do_afremmen_noord() {

}

//exit

void exit_afremmen_noord() {

}

////RIJDEN_ZUID

//entry
void entry_rijden_zuid() {

  zuidLichtenGroen();
  resetDelayTimer();
}

//do

void do_rijden_zuid() {

}

//exit

void exit_rijden_zuid() {

}

////AFREMMEN_ZUID

void entry_afremmen_zuid() {
  zuidLichtenGeel();
  resetDelayTimer();
}

//do

void do_afremmen_zuid() {

}

//exit

void exit_afremmen_zuid() {

}

////OVERSTEKEN

//entry
void entry_oversteken() {

  showLopen();
  resetDelayTimer();
}

//do
void do_oversteken() {
  buzzerBeep(300);

}

//exit

void exit_oversteken() {
  clearShiftRegister();
}

////DODENTIJD

//entry
void entry_dodentijd() {
  verschuifWachtrij();
  alleStoplichtenRood();
  resetDelayTimer();
  clearShiftRegister();
}

//do

void do_dodentijd() {

}

//exit

void exit_dodentijd() {

}

////OPENSLAGBOOM

//entry
void entry_openslagboom() {
  resetDelayTimer();
}

//do

void do_openslagboom() {
  buzzerBeep(300);
  slagboomOpen();
}

//exit

void exit_openslagboom() {
  
}

////SLUITSLAGBOOM

//entry
void entry_sluitslagboom() {
  resetDelayTimer();
  showStopteken();
}

//do

void do_sluitslagboom() {
  slagboomSluiten();
  buzzerBeep(100);
}

//exit

void exit_sluitslagboom() {

}


////COUNTDOWN


//entry
void entry_countdown() {
  resetDelayTimer();
  isCountDownKlaar = false;
  previousMillisCountDown = millis();
}

//do

void do_countdown() {
  countDown();
   buzzerBeep(100);
}

//exit

void exit_countdown() {

}



////openslagboom  nacht

//entry
void entry_openslagboom_nacht() {
  showStopteken();
}

//do
void do_openslagboom_nacht() {
  slagboomOpen();
  buzzerBeep(500);
}

//exit
void exit_openslagboom_nacht() {

}

////nachtstand

//entry
void entry_nachtstand() {
  showWaarschuwingsteken();
}
//do
void do_nachtstand() {
  waarschuwingsLicht(1000);
}

//exit
void exit_nachtstand() {

}
////sluitslagboom nacht

//entry
void entry_sluitslagboom_nacht() {
  showStopteken();
  noordLichtenGeel();
  zuidLichtenGeel();

}

//do
void do_sluitslagboom_nacht() {

  slagboomSluiten();
  buzzerBeep(500);

}

//exit
void exit_sluitslagboom_nacht() {

}
