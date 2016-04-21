#include <Arduino.h>

class Luz{
private:
  #define pinLuz 10

public:
  Luz();
  void encenderLuz();
  void apagarLuz();
  void parpadeo();
};

