#include <Arduino.h>
#include <Servo.h>

Servo motor;
enum mode { eco, normal, performance };

int throttlePin = A0;
int throttle = 0;
int speed = 1505;
int realSpeed = 1505;
mode currentMode = eco;

void setup() {
  motor.attach(3);
  motor.writeMicroseconds(1505);
}

void loop() {
  throttle = analogRead(throttlePin);
  speed = map(throttle, 1023, 0, 1505, 2000);

  if (realSpeed < speed) {
    realSpeed++;
  }

  if (realSpeed > speed) {
    realSpeed--;
  }

  switch (currentMode) {
    case eco:
      delay(10);
      break;
    case normal:
      delay(5);
      break;
    case performance:
      delay(3);
      break;
  }

  realSpeed = constrain(realSpeed, 1505, 2000);
  motor.writeMicroseconds(realSpeed);
}
