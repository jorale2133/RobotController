#include <ESP32Servo.h>

static const int servoPin = 33;
Servo servo1;

void setup() {

  Serial.begin(115200);
  servo1.attach(servoPin);
}

void loop() {
  
  for(int posDegrees = 20; posDegrees <= 170; posDegrees++) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(200);
  }

  for(int posDegrees = 170; posDegrees >= 20; posDegrees--) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(200);
  }

}