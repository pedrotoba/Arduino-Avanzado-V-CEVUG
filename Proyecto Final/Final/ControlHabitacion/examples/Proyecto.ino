#include "Menu.h"
#include <LiquidCrystal.h>

//Declaracion de variables
LiquidCrystal lcd(12,11,5,4,3,2);
Menu m;
int x=0;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {

 //Llamada a las funciones para mostrar el menú
 x = m.MenuPrincipal(lcd);
  m.Limpiar(lcd);
  if(x == 1){
    m.MenuLuz(lcd);
  }
  else{
    m.MenuVentilador(lcd);
  }
 
}
