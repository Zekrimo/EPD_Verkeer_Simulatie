//pin waardes voor shiftregister
const int ST_CP = 12;  //latchpin
const int DS = 13;     //datapin
const int SH_CP = 11; //clockpin

const int LEEGEWAARDE_DISPLAY = B00000000;

//setup functie voor shiftregister
void setupShiftRegister() {
  pinMode(ST_CP, OUTPUT); //latchpin
  pinMode(SH_CP, OUTPUT); //clockpin
  pinMode(DS, OUTPUT);    //datapin
}

//functie voor leegmaken van shiftregister
void clearShiftRegister() {
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, MSBFIRST, LEEGEWAARDE_DISPLAY);
  digitalWrite(ST_CP, HIGH);

}

// functie om waarde te tonen op segmentdisplay doormiddel van shiftregister
// waardes zijn te vinden op tabblad 7SegmentDisplay
void showDigit(byte digit) {
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, MSBFIRST, digit);
  digitalWrite(ST_CP, HIGH);
}
