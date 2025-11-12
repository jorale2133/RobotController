#include <FourDOFController.h>
#include <ESP32Servo.h>

FourDOFController::FourDOFController(int pinS1, int pinS2, int pinS3, int pinS4){
    servo[0].attach(pinS1);
    servo[1].attach(pinS2);
    servo[2].attach(pinS3);
    servo[3].attach(pinS4);

    dx1=90;
    dx2=20;
    dx3=60;
    dx4=120;
}

//Se puede simplificar a una sola función
//Mueve sel servo de la base
void FourDOFController::moveMotor1(int J1VRX){    
    if (dx1 >= 0 && dx1 <= 180) {

        if(J1VRX < 900){
            dx1++;
        }      

        if (J1VRX < 400) {
            dx1+=2;
        }  
        
        if (J1VRX > 2000 ) {
            dx1--;
        }

        if(J1VRX > 3500){
            dx1-=2;
        }
    }   
    dx1 = constrain(dx1, 0, 180);
    servo[0].write(dx1);
    //Serial.print("Dx1: ");
    //Serial.println(dx1);
}

// mueve elservo motor de la izquierdo
void FourDOFController::moveMotor2(int J1VRY){    
    if (dx2 >= 0 && dx2 <= 100) {
    
        if(J1VRY < 900){
            dx2++;
        }      

        if (J1VRY < 400) {
            dx2+=2;
        }  
        
        if (J1VRY > 2000 ) {
            dx2--;
        }

        if(J1VRY > 3500){
            dx2-=2;
        }
    }
    
    dx2 = constrain(dx2, 0, 100);
    servo[1].write(dx2);
    //Serial.print("Dx1: ");
    //Serial.println(dx1);
}


//Mueve el servo motor de la derecha
void FourDOFController::moveMotor3(int J2VRY){    
    if (dx3 >= 0 && dx3 <= 140) {

        if(J2VRY < 900){
            dx3--;
        }      

        if (J2VRY < 400) {
            dx3-=2;
        }  
        
        if (J2VRY > 2000 ) {
            dx3++;
        }

        if(J2VRY > 3500){
            dx3+=2;
        }
    }   
    dx3 = constrain(dx3, 0, 140);
    servo[2].write(dx3);
    //Serial.print("Dx1: ");
    //Serial.println(dx1);
}

// mueve el servo motor de la garra
void FourDOFController::moveMotor4(int J2VRX){    
    if (dx4 >= 0 && dx4 <= 180) {
    
        if(J2VRX < 900){
            dx4++;
        }      

        if (J2VRX < 400) {
            dx4+=2;
        }  
        
        if (J2VRX > 2000 ) {
            dx4--;
        }

        if(J2VRX > 3500){
            dx4-=2;
        }
    }
    
    dx4 = constrain(dx4, 0, 180);
    servo[3].write(dx4);
    //Serial.print("Dx1: ");
    //Serial.println(dx1);
}


