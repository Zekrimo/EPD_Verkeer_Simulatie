void setup() {
  Serial.begin(9600);
  setupShiftRegister();
  setupLed();
  setupPotmeter();
  setupBuzzer();
  setupButtons();
  servoSetup();
  clearShiftRegister();
  setupStateMachine();
}

void loop() {

//// debug functie voor potmeter, ter vervanging van lichtsensor
//   Serial.println( getMappedPotmeterValue(10));

//// debug functie voor tonen van de wachtrij
   showWachtrij();
  checkButton();
  loopStateMachine();
}
