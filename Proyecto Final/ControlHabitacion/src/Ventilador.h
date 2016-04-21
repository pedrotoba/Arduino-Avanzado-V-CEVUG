#include <Arduino.h>

class Ventilador{
private:
  #define pinVen 9

public:
  Ventilador();
  void encenderVen();
  void apagarVen();
};

