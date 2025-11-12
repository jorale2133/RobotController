#include <HW504.h>

HW504::HW504(uint8_t analogPin1, uint8_t analogPin2, uint8_t digitalPin) {
  pinA1 = analogPin1;
  pinA2 = analogPin2;
  pinD1 = digitalPin;
}

HW504::HW504(uint8_t analogPin1, uint8_t analogPin2) {
  pinA1 = analogPin1;
  pinA2 = analogPin2;
}

void HW504::iniciar() {

  pinMode(pinA1, INPUT);
  pinMode(pinA2, INPUT);
  Serial.println("Todo listo....");
}

int HW504::leerAnalogico1() {
  return analogRead(pinA1);
}

int HW504::leerAnalogico2() {
  return analogRead(pinA2);
}

bool HW504::leerDigital() {
  return digitalRead(pinD1);
}

