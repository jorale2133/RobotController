#include "HW504.h"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Cargando...");
  J1.iniciar();
  J2.iniciar();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("A1: ");
  Serial.print(J1.leerAnalogico1());
  Serial.print(" A2: ");
  Serial.print(J1.leerAnalogico2());
  Serial.print(" A3: ");
  Serial.print(J2.leerAnalogico1());
  Serial.print(" A4: ");
  Serial.println(J2.leerAnalogico2());  
  delay(500);

}
