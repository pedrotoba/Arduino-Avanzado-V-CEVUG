#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Luces.h"
#include "Ventilador.h"

using namespace std;

class Menu{

private:
  //Boton derecho
  #define botSelec 7
  //Boton izquierdo
  #define botBaj 8
  Luz bombilla;
  Ventilador ven;
  
public:

  Menu();
  void MostrarError(LiquidCrystal l);
  void Limpiar(LiquidCrystal l);
  bool MenuLuz(LiquidCrystal l);
  bool MenuVentilador(LiquidCrystal l);
  int MenuPrincipal(LiquidCrystal l);
  bool pulsacionSelec();
  bool pulsacionBaj();
  
};

