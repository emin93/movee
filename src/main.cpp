#include <Arduino.h>
#include <Servo.h>

Servo motor;
enum mode { eco, normal, performance };

int throttlePin = A0;
int throttle = 0;
int speed = 1505;
int realSpeed = 1505;
int maxSpeed = 2000;
mode currentMode = eco;

void setup() {
  motor.attach(3);
  motor.writeMicroseconds(1505);
}

void loop() {
  switch (currentMode) {
    case eco:
      maxSpeed = 1800;
      break;
    case normal:
      maxSpeed = 1800;
      break;
    case performance:
      maxSpeed = 2000;
      break;
  }

  throttle = analogRead(throttlePin);
  speed = map(throttle, 1023, 0, 1505, maxSpeed);

  if (realSpeed < speed) {
    realSpeed++;
    delay(20);
  }

  if (realSpeed > speed) {
    realSpeed--;
  }

  realSpeed = constrain(realSpeed, 1505, 2000);
  motor.writeMicroseconds(realSpeed);
}
