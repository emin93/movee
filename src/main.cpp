#include <Arduino.h>
#include <Servo.h>

Servo motor;

int throttle = A0;
int throttleValue = 0;
int speed = 1505;
int realSpeed = 1505;

void setup() {
  motor.attach(3);
  motor.writeMicroseconds(1505);
}

void loop() {
  throttleValue = analogRead(throttle);
  speed = map(throttleValue, 1020, 600, 1505, 2000);
  speed = constrain(speed, 1505, 2000);

  if (speed > realSpeed) {
    realSpeed = realSpeed + 1;
    delay(3);
  }

  if (speed < realSpeed) {
    realSpeed = realSpeed - 1;
    delay(3);
  }

  realSpeed = constrain(realSpeed, 1505, 2000);
  motor.writeMicroseconds(realSpeed);
}
