#include <Arduino.h>

class LEDT{
private:
  #define R1 8
  #define R2 7
  #define V1 6
public:
  LEDT();
  void highAll();
  void lowAll();
  void Parpadear();
  void green(volatile int estado);
  void red(volatile int estado);
};

