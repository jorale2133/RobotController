#include <HW504.h>
#include <FourDOFController.h>

HW504 J1(A0, A3);
HW504 J2(A6, A7);

FourDOFController robot(25, 26, 27, 33);

void setup() {

  Serial.begin(115200);
  J1.iniciar();
  J2.iniciar();
  Serial.println("ESP32 listo...");
  
}

void loop() {
  
  if(Serial.available()>0){
    Serial.println("Conectado con python.");
  }

//  imprimir_valor();

  robot.moveMotor1(J1.leerAnalogico1());
  robot.moveMotor2(J1.leerAnalogico2());
  robot.moveMotor3(J2.leerAnalogico2());
  robot.moveMotor4(J2.leerAnalogico1());

  delay(10);
}

void imprimir_valor(){
  // put your main code here, to run repeatedly:
  Serial.print("A1: ");
  Serial.print(J1.leerAnalogico1());
  Serial.print(" A2: ");
  Serial.print(J1.leerAnalogico2());
  Serial.print(" A3: ");
  Serial.print(J2.leerAnalogico1());
  Serial.print(" A4: ");
  Serial.println(J2.leerAnalogico2());  
}
