#ifndef FourDOFController_h
#define FourDOFController_h

#include <Arduino.h>
#include <ESP32Servo.h>

class FourDOFController
{
private:
    Servo servo[4];
    int dx1;
    int dx2;
    int dx3;
    int dx4;

public:
    FourDOFController(int pinS1, int pinS2, int pinS3,int pinS4);
    void moveMotor1(int J1VRX);
    void moveMotor2(int J1VRY);
    
    void moveMotor3(int J2VRX);
    void moveMotor4(int J2VRY);

};

#endif