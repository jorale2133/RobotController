#include <ESP32Servo.h>

static const int servoPin1 = 25;

int Vrx1 = A15; // input pin for joystick1 X
int Vry1 = A16; // input pin for joystick1 Y
int Vrx2 = A17; // input pin for joystick2 X
int Vry2 = A19; // input pin for joystick2 Y

struct JoyStick {
  int vrx;
  int vry;
};

JoyStick stick1;
JoyStick stick2;

Servo servo1;

int dx1 = 90;
void setup() {
  Serial.begin(115200);
  stick1.vrx = 0;
  stick1.vry = 0;
  stick2.vrx = 0;
  stick2.vry = 0;

  servo1.attach(servoPin1);
}

void loop() {
  stick1.vrx = analogRead(Vry1);
  stick1.vry = analogRead(Vrx1);
  stick2.vrx = analogRead(Vrx2);
  stick2.vry = analogRead(Vry2);

  moveServoMotor1(stick1.vrx);

/*
  Serial.print("Stick 1 - X: ");
  Serial.print(stick1.vrx);
  Serial.print(" | Y: ");
  Serial.println(stick1.vry);

  Serial.print("Stick 2 - X: ");
  Serial.print(stick2.vrx);
  Serial.print(" | Y: ");
  Serial.println(stick2.vry);
*/
  delay(20);
}

void moveServoMotor1(int x1){

    if(x1 == 0 && dx1 > 0 && dx1 < 180){
      dx1++;
      if(dx1==180)
        dx1--;
    }



    if(x1 == 4095 && dx1 >0 && dx1 < 180){
      dx1--;
      if(dx1==0)
        dx1++;  
    }
    
    servo1.write(dx1);
    Serial.println(dx1);
}