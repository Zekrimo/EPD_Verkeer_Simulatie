//potmeter pin waarde
const int POTMETERPIN = A0;

//setup functie voor potmeter
void setupPotmeter() {
  pinMode(POTMETERPIN, INPUT);
}

//return functie voor potmeterwaarde
int getPotmeterValue() {
  return analogRead(POTMETERPIN);
}

//map de potmeterwaarde tussen 1 en een gegeven waarde
int getMappedPotmeterValue (int max) {
  return map(getPotmeterValue(), 0, 1023, 1, max);

}
