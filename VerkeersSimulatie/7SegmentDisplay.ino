//array met de cijfers er in verwerkt
const byte CIJFERS[] = {B11111010, B01100000, B11011101, B11110100, B01100110, B10110110, B10111110};
const int CIJFERS_SIZE = 7;

////bitwaardes voor cijfers voor naslag
//const int ZERO              = B11111010;
//const int ONE               = B01100000;
//const int TWO               = B11011101;
//const int THREE             = B11110100;
//const int FOUR              = B01100110;
//const int FIVE              = B10110110;
//const int SIX               = B10111110
const int LOOPTEKEN           = B00011010;
const int STOPTEKEN           = B01101110;
const int WAARSCHUWINGSTEKEN  = B10101000;


//functies
void showStopteken() {
  clearShiftRegister();
  showDigit(STOPTEKEN);
}

void showLopen() {
  clearShiftRegister();
  showDigit(LOOPTEKEN);
}

void showWaarschuwingsteken() {
  clearShiftRegister();
  showDigit(WAARSCHUWINGSTEKEN);
}
