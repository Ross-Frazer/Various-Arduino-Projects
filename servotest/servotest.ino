#include <Servo.h>

const int servo = 9;

Servo myServo;
int val = 0;

void setup() {
  myServo.attach(servo);
  myServo.write(180);
}

void loop() {

}
