#ifndef HW504_h
#define HW504_h

#include  <Arduino.h>

class HW504{
    private:
        uint8_t pinA1;
        uint8_t pinA2;
        uint8_t pinD1;
    
    public:
        HW504(uint8_t analogPin1, uint8_t analogPin2, uint8_t digitalPin);
        HW504(uint8_t analogPin1, uint8_t analogPin2);
        void iniciar();
        int leerAnalogico1();
        int leerAnalogico2();
        bool leerDigital();
};

#endif