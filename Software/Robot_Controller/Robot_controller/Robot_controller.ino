#include <ESP32Servo.h>

static const int servoPin1 = 25; //Pin Servo 1
static const int servoPin2 = 33; //Pin Servo 2
static const int servoPin3 = 32; //Pin servo 3
static const int servoPin4 = 34; //Pin Servo 4

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
Servo servo2;
Servo servo3;
Servo servo4;

int dx1 = 90; //1<dx1<180
int dx2 = 20;
int dx3 = 0;
int dx4 = 90;

void setup() {
  Serial.begin(115200);
  stick1.vrx = 0;
  stick1.vry = 0;
  stick2.vrx = 0;
  stick2.vry = 0;

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
}

void loop() {
  stick1.vrx = analogRead(Vry1);
  stick1.vry = analogRead(Vrx1);
  stick2.vrx = analogRead(Vrx2);
  stick2.vry = analogRead(Vry2);

  moveServoMotor1(stick1.vrx);
  moveServoMotor2(stick1.vry);

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
  delay(30);
}

void moveServoMotor1(int x1){

    if(x1 == 0 && dx1 > 0 && dx1 < 180){
      dx1++;
      if(dx1==180)
        dx1--;
    }

    if(x1 == 4095 && dx1 > 0 && dx1 < 180){
      dx1--;
      if(dx1==0)
        dx1++;  
    }   
    servo1.write(dx1);
    Serial.print("Dx1: ");
    Serial.println(dx1);
}

void moveServoMotor2(int x2){
     if(x2 == 4095 && dx2 > 0 && dx2 < 180){
      dx2++;
      if(dx2==180)
        dx2--;
    }

    if(x2 == 0 && dx2 > 0 && dx2 < 180){
      dx2--;
      if(dx2==0)
        dx2++;  
    }   
    servo2.write(dx2);
    Serial.print("Dx2: ");
    Serial.println(dx2); 
}