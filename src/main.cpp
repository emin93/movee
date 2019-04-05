#include <Arduino.h>
#include <Servo.h>

Servo motor;
enum mode { eco, normal, performance };

int throttlePin = A0;
int throttle = 0;
int speed = 1505;
int realSpeed = 1505;
int maxSpeed = 2000;
mode currentMode = performance;

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
  speed = map(throttle, 180, 853, 1501, maxSpeed);

  if (realSpeed < speed) {
    realSpeed++;
  }

  if (realSpeed > speed) {
    realSpeed--;
  }

  delay(3);

  realSpeed = constrain(realSpeed, 1501, 2000);
  motor.writeMicroseconds(realSpeed);
}
