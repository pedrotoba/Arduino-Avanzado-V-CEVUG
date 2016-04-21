#include "Menu.h"

using namespace std;

//Constructor por defecto que inicializa los botones
Menu::Menu(){
  pinMode(botSelec,INPUT);
  pinMode(botBaj,INPUT);
}

//Mensaje de error
void Menu::MostrarError(LiquidCrystal l){
  l.setCursor(0,1);
  l.print("ERROR");
}

//Borra lo que hay en la pantalla
void Menu::Limpiar(LiquidCrystal l){
  l.clear();
}

//Creación del menu para el ventilador
bool Menu::MenuVentilador(LiquidCrystal l){
  int actual = 0;
  bool fin = false;
  
  do{
    switch(actual){
      case 0:
        l.setCursor(0,0);
        l.write("Menu:");
        l.setCursor(0,1);
        l.write(">Encender Vent");
        if(digitalRead(botSelec)==HIGH) ven.encenderVen();
      break;
      case 1:
          l.setCursor(0,0);
          l.print("Menu:");
          l.setCursor(0,1);
          l.print(">Apagar Vent");
          if(digitalRead(botSelec)==HIGH) ven.apagarVen();
      break;
   }
   if(digitalRead(botBaj)==HIGH){
         actual = actual + 1; 
   }
   actual = actual%2;
   if(digitalRead(botSelec)==HIGH && digitalRead(botBaj)==HIGH){
    fin = true;
   }
  }while(!fin);
  
  return fin;
}

//Creación del menú para la luz
bool Menu::MenuLuz(LiquidCrystal l){
  int actual = 0;
  bool fin = false;
  
  do{
    switch(actual){
      case 0:
        l.setCursor(0,0);
        l.write("Menu:");
        l.setCursor(0,1);
        l.write(">Encender Luz");
        if(digitalRead(botSelec)==HIGH) bombilla.encenderLuz();
      break;
      case 1:
          l.setCursor(0,0);
          l.print("Menu:");
          l.setCursor(0,1);
          l.print(">Apagar Luz");
          if(digitalRead(botSelec)==HIGH) bombilla.apagarLuz();
      break;
      case 2:
        l.setCursor(0,0);
        l.print("Menu:");
        l.setCursor(0,1);
        l.print(">Parpadear Luz");
         if(digitalRead(botSelec)==HIGH) bombilla.parpadeo();  
      break;
   }
   if(digitalRead(botBaj)==HIGH){
         actual = actual + 1; 
   }
   actual = actual%3;
   if(digitalRead(botSelec)==HIGH && digitalRead(botBaj)==HIGH){
    fin = true;
   }
  }while(!fin);
  
  return fin;
}

//Mne principal que selecciona cualquiera de los 2 menus
int Menu::MenuPrincipal(LiquidCrystal l){
  int actual = 0;
  bool fin = false;
  int eleccion=0;

  do{
    switch(actual){
      case 0:
        l.setCursor(0,0);
        l.print("Menu de luces");
        if(digitalRead(botSelec)==HIGH){
          eleccion = 1;
          fin = true;
        }  
      break;
      
      case 1:
        l.setCursor(0,0);
        l.print("Menu ventilador");
        if(digitalRead(botSelec)==HIGH){
          eleccion = 2;
          fin = true;
        }
      break;
    }
    if(digitalRead(botBaj)==HIGH){
         actual = actual + 1; 
         l.clear();
   }
   actual = actual%2;
    
  }while(!fin);

  return eleccion;
}

//Funcion para saber si se ha pulsado el botón derecho
bool Menu::pulsacionSelec(){
  bool pulsado;
  int valor;
  valor = digitalRead(botSelec);
  if(valor == HIGH) pulsado = true;
  else pulsado = false;

  return pulsado;
}

//Funcion para saber si se ha pulsado el botón izquierdo
bool Menu::pulsacionBaj(){
  bool pulsado;
  int valor;
  valor = digitalRead(botBaj);
  if(valor == HIGH) pulsado = true;
  else pulsado = false;

  return pulsado;
}

