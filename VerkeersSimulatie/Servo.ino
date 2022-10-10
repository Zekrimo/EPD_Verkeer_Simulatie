#include <Servo.h>
Servo servo;

//servo slagboom posities
int servoPositie = 0;
const int SLAGBOOM_OPEN = 90;
const int SLAGBOOM_DICHT = 10;

//servo aansluit pin
const int SERVOPIN = 10;

//servo software timer
unsigned long currentMillisServo;
unsigned long previousMillisServoBeweeg = 0;
const int SERVO_UPDATE_INTERVAL = 50;

//setup functie voor de servo
void servoSetup() {
  servo.attach(SERVOPIN);
  updateServo(SLAGBOOM_DICHT);
}

////functies
//zet servo naar positie X
void servoNaarPositie(int positie) {
  servo.write(positie);
  servoPositie = positie;
}

//zet servo naar positite X doormiddel van software timer
void updateServo(int targetPositie) {
  currentMillisServo = millis();

  if (currentMillisServo - previousMillisServoBeweeg >= SERVO_UPDATE_INTERVAL) {
    previousMillisServoBeweeg = currentMillisServo;
    if (servoPositie > targetPositie) {
      servoNaarPositie(servoPositie - 1);
    } else if (servoPositie < targetPositie) {
      servoNaarPositie(servoPositie + 1);
    }
  }

}

// functie voor sluiten van slagboom
void slagboomSluiten() {
  updateServo(SLAGBOOM_DICHT);

}

//functie voor openen van slagboom
void slagboomOpen() {
  updateServo(SLAGBOOM_OPEN);

}
