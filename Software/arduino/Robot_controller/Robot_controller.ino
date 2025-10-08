#include <ESP32Servo.h>

static const int servoPin1 = 25; //Pin Servo 1
static const int servoPin2 = 33; //Pin Servo 2
static const int servoPin3 = 32; //Pin servo 3
static const int servoPin4 = 34; //Pin Servo 4

const uint8_t Vrx1 = A10;
const uint8_t Vry1 = A11;
const uint8_t Vrx2 = A12;
const uint8_t Vry2 = A13;

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
int dx3 = 10;
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

  read_joystick();

  moveServoMotor1(stick1.vrx);
  moveServoMotor2(stick1.vry);

  moveServoMotor3(stick2.vrx);
  moveServoMotor4(stick2.vry);

  delay(30);
}

void read_joystick(){
  stick1.vrx = analogRead(Vrx1);
  stick1.vry = analogRead(Vry1);
  stick2.vrx = analogRead(Vrx2);
  stick2.vry = analogRead(Vry2);

// Imprimir en formato compatible con Serial Plotter
  Serial.print(stickVrx1);
  Serial.print("\t");       // separador
  Serial.print(stick1.vry);
  Serial.print("\t");
  Serial.print(stick2.vrx);
  Serial.print("\t");
  Serial.println(stick2.vry);  // último valor + salto de línea
}

//Mueve el servo motor de la base
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
    //Serial.print("Dx1: ");
    //Serial.println(dx1);

}

// mueve elservo motor de la izquierdo
void moveServoMotor2(int x2){
     if(x2 == 4095 && dx2 > 0 && dx2 < 120){
      dx2++;
      if(dx2==120)
        dx2--;
    }

    if(x2 == 0 && dx2 > 0 && dx2 < 120){
      dx2--;
      if(dx2==0)
        dx2++;  
    }   
    servo2.write(dx2);
    //Serial.print("Dx2: ");
    //Serial.println(dx2); 
}

// Mueve el servo motor de lalado derecho derecho 
void moveServoMotor3(int x3){
     if(x3 == 0 && dx3 > 0 && dx3 < 100){
      dx3++;
      if(dx3==100)
        dx3--;
    }

    if(x3 == 4095 && dx3 > 0 && dx3 < 100){
      dx3--;
      if(dx3==0)
        dx3++;  
    }   
    servo3.write(dx3);
    //Serial.print("Dx3: ");
    //Serial.println(dx3); 
}

//Mueve el servomotor del manipulador
void moveServoMotor4(int x4){
     if(x4 == 0 && dx4 > 0 && dx4 < 180){
      dx4++;
      if(dx4==180)
        dx4--;
    }

    if(x4 == 4095 && dx4 > 0 && dx4 < 180){
      dx4--;
      if(dx4==0)
        dx4++;  
    }   
    servo4.write(dx4);
    //Serial.print("Dx4: ");
    //Serial.println(dx4); 
}
